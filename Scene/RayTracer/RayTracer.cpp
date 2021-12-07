//
// Created by Екатерина on 09.10.2021.
//
#include "RayTracer.h"
RayTracer::RayTracer(double vw, double vh, int depth)
{
    this->vh = vh;
    this->vw = vw;
    this->depth = depth <= 0 || depth > 10 ? 2 : depth;
}
double RayTracer::canvas_to_viewport(double coord, double canvas, double viewport)
{
    return viewport * (coord / canvas);
}
Point RayTracer::changeRayDirection(Point p, Matrix<double> camera_rotation)
{
    Matrix<double> d({{p.getX()},
                      {p.getY()},
                      {p.getZ()}});
    Matrix<double> res = camera_rotation * d;
    return Point(res[0][0], res[1][0], res[2][0]);
}
void RayTracer::draw(std::shared_ptr<Drawer> &drawer, std::vector<std::shared_ptr<Light>> &lights,
                     std::vector<std::shared_ptr<Object>> &surfaces, std::shared_ptr<Camera> &cam)
{
    int planeZ = 1;
    int cw, ch;
    drawer->getSceneSizes(cw, ch);

    std::vector <std::thread> threads(8);
    std::vector<DrawerColor> colors(8);
    std::vector<pair<int, int>> coords(8);
    int counter = 0;
    for (int x = -cw / 2; x <= cw / 2; x++)
    {
        for (int y = -ch / 2; y <= ch / 2; y++)
        {
            if (counter == 8)
            {
                for (int i = 0; i < 8; ++i) {
                    threads[i].join();
                }
                for (int i = 0; i < 8; ++i)
                    drawer->drawPixel(coords[i].first, coords[i].second, colors[i]);
                counter = 0;
            }

            Point viewportPoint(canvas_to_viewport(x, cw, vw),
                                canvas_to_viewport(y, ch, vh),
                                planeZ);
            Point d = changeRayDirection(viewportPoint, cam->getDirection());
            threads[counter] = std::thread(&RayTracer::traceRay, this, std::ref(surfaces), std::ref(lights), cam->getPosition(), d, 1, INT_MAX, depth, std::ref(colors[counter]));
            coords[counter] = std::pair<int, int>(x, -y);
            counter++;
        }
    }
    for (int i = 0; i < counter; ++i) {
        threads[i].join();
    }
    for (int i = 0; i < counter; ++i)
        drawer->drawPixel(coords[i].first, coords[i].second, colors[i]);

}
void RayTracer::closestIntersection(std::vector<std::shared_ptr<Object>> &surfaces, Point beg, Point end, double tmin, double tmax, int &closest_surface, double &closest_t)
{
    closest_t = INT_MAX;
    closest_surface = -1;
    for (int i = 0; i < surfaces.size(); i++)
    {
        std::vector<double> t;
        surfaces[i]->getIntersection(beg, end, t);
        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] > tmin && t[j] < tmax && t[j] < closest_t) {
                closest_t = t[j];
                closest_surface = i;
            }
        }

    }
}
bool RayTracer::isExistIntersection(std::vector<std::shared_ptr<Object>> &surfaces, Point beg, Point end, double tmin, double tmax)
{
    for (int i = 0; i < surfaces.size(); i++)
    {
        std::vector<double> t;
        surfaces[i]->getIntersection(beg, end, t);
        for (int j = 0; j < t.size(); j++)
        {
            if (t[j] > tmin && t[j] < tmax) {
                return true;
            }
        }
    }
    return false;
}
Point RayTracer::mirrorRay(Point ray, Point normal)
{
    return normal * (2 * normal.scalarMul(ray)) - ray;
}
Point RayTracer::refrRay(Point ray, Point normal, double n1, double n2) // нормаль и луч в точку падения
{
    double mul = normal.scalarMul(ray);
    int sign = mul >= 0 ? 1 : -1;
    double G = sign * sqrt(n2*n2 - n1*n1 + mul * mul) - mul;
    return ray + normal * G;
}
double RayTracer::computeLighting(std::vector<std::shared_ptr<Object>> &surfaces, std::vector<std::shared_ptr<Light>> &lights, Point p, Point n, Point v, double s)
{
    double intensity = 0.0;
    double tmax;
    for (int i = 0; i < lights.size(); i++){
        if (lights[i]->getType() == AMBIENT)
        {
            intensity += lights[i]->getIntensityInPoint(p, n, v, s);
            continue;
        }
        if (lights[i]->getType() == POINT)
        {
            tmax = 1;
        } else {
            tmax = INT_MAX;
        }
        if (isExistIntersection(surfaces, p, lights[i]->getLightDirection(p), 0.001, tmax))
            continue;
        intensity += lights[i]->getIntensityInPoint(p, n, v, s);
    }
    if (intensity > 1)
        intensity = 1;
    return intensity;
}
DrawerColor RayTracer::traceRay(std::vector<std::shared_ptr<Object>> &surfaces, std::vector<std::shared_ptr<Light>> &lights, Point o, Point d, double tmin, double tmax, int depth, DrawerColor &tmp)
{
    int closest_surface;
    double closest_t;
    closestIntersection(surfaces, o, d,  tmin, tmax, closest_surface, closest_t);
    if (closest_surface == -1) {
        tmp = DrawerColor(0, 0, 0);
        return DrawerColor(0, 0, 0);
    }
    Point p = o + d * closest_t;
    Point normal;
    surfaces[closest_surface]->getNormal(p, normal);


    double i = computeLighting(surfaces, lights, p, normal, -d, surfaces[closest_surface]->getShineCoef());
    DrawerColor color = surfaces[closest_surface]->getColor();
    color *= i;

    double mirrorCoef = surfaces[closest_surface]->getMirrorCoef();
    if (!(depth <= 0 || mirrorCoef <= 0))
    {
        DrawerColor mirrorColor = traceRay(surfaces, lights, p, mirrorRay(-d, normal), 0.001, INT_MAX, depth - 1, tmp);
        color = color * (1 - mirrorCoef) + mirrorColor * mirrorCoef;
    }

    double transpCoef = surfaces[closest_surface]->getTranspCoef();
    if (transpCoef > 0)
    {
        Point ray = refrRay(d, -normal, 1, surfaces[closest_surface]->getRefrCoef());
        ray *= 1 / ray.length();
        Point peps = p + ray * 1.5; //
        Point rray = refrRay(peps, -normal, surfaces[closest_surface]->getRefrCoef(), 1);
        DrawerColor transpColor = traceRay(surfaces, lights, p, rray, 0.001, INT_MAX, depth, tmp);
        color = color * (1 - transpCoef) +  transpColor * transpCoef;
    }

    tmp = color;
    return color;
}
/*void View::testTime()
{
    Matrix<double> camera_rotation = {{1, 0, 0},
                                      {0, 1, 0},
                                      {0, 0, 1}};
    Point o = {0, 0, 0};
    for (int i = 1; i < 6; i++) {
        int cw = i * 100;
        int ch = i * 100;
        std::cout << cw << "\n";
        double time = 0;
//        scene->setSceneRect(-cw / 2,  -ch / 2, cw, ch);
        for (int j = 0; j < 6 - i; j++) {
            clock_t sTime = clock();
            drawSceneMulti(cw, ch, 1.0, 1.0, o, camera_rotation, 1);
            clock_t eTime = clock();
            time += eTime - sTime;
            std::cout << eTime - sTime << " ";
        }
        std::cout << "\n";
        time /= 0.001 * CLOCKS_PER_SEC * (6 - i) ;
        std::cout << time << "\n";
    }
}*/
//QColor RayTracer::traceRay(Point o, Point d, double tmin, double tmax, int depth, int obj_id, QColor &tmp)
//{
//    int closest_surface;
//    double closest_t;
//    closestIntersection(o, d,  tmin, tmax, closest_surface, closest_t);
//    if (closest_surface == -1) {
//        tmp = QColor(0, 0, 0);
//        return QColor(0, 0, 0);
//    }
//    Point p = o + d * closest_t;
//    Point normal;
//    surfaces[closest_surface]->getNormal(p, normal);
//
//
//    double i = computeLighting(p, normal, -d, surfaces[closest_surface]->getShineCoef());
//    QColor color = surfaces[closest_surface]->getColor();
//    color = mulColor(color, i);
//
//    double mirrorCoef = surfaces[closest_surface]->getMirrorCoef();
//    if (!(depth <= 0 || mirrorCoef <= 0))
//    {
//        QColor mirrorColor = traceRay(p, mirrorRay(-d, normal), 0.001, INT_MAX, depth - 1, closest_surface, tmp);
//        color = sumColor(mulColor(color, (1 - mirrorCoef)),
//                               mulColor(mirrorColor, mirrorCoef));
//    }
//
//    double transpCoef = surfaces[closest_surface]->getTranspCoef();
//    if (transpCoef > 0)
//    {
//        Point ray = refrRay(d, -normal, 1, surfaces[closest_surface]->getRefrCoef());
//        Point peps = p + ray * 0.1;
//        Point rray = refrRay(peps, -normal, surfaces[closest_surface]->getRefrCoef(), 1);
//        QColor transpColor = traceRay(p, rray, 0.001, INT_MAX, depth, obj_id, tmp);
//        color = sumColor(mulColor(color, (1 - transpCoef)),
//                                     mulColor(transpColor, transpCoef));
//    }
//    tmp = color;
//    return color;
//}