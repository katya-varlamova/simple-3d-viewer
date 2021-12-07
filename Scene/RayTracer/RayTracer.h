//
// Created by Екатерина on 09.10.2021.
//

#ifndef VIEWER_RAYTRACER_H
#define VIEWER_RAYTRACER_H
#include <thread>
#include "../../Primitives/Point.h"
#include "../../Primitives/Surfaces/Object.h"
#include "../../Primitives/Surfaces/Surface.h"
#include "../../Primitives/Surfaces/CompositeSurface.h"
#include "../../Primitives/Light/AmbientLight.h"
#include "../../Primitives/Light/PointLight.h"
#include "../../Primitives/Light/DirectionalLight.h"
#include "../DrawerAlgo.h"
#include "../../Primitives/Camera/Camera.h"
#include "../../Drawer/Drawer.h"
class RayTracer : public DrawerAlgo{
public:
    RayTracer(double vw, double vh, int depth);
    virtual void draw(std::shared_ptr<Drawer> &drawer, std::vector<std::shared_ptr<Light>> &lights, std::vector<std::shared_ptr<Object>> &surfaces, std::shared_ptr<Camera> &camera) override;
protected:
    double vw, vh;
    int depth;
private:
    double canvas_to_viewport(double coord, double canvas, double viewport);
    Point changeRayDirection(Point p, Matrix<double> camera_rotation);
    DrawerColor traceRay(std::vector<std::shared_ptr<Object>> &surfaces, std::vector<std::shared_ptr<Light>> &lights, Point o, Point d, double tmin, double tmax, int depth, DrawerColor &tmp);
    bool isExistIntersection(std::vector<std::shared_ptr<Object>> &surfaces, Point beg, Point end, double tmin, double tmax);
    void closestIntersection(std::vector<std::shared_ptr<Object>> &surfaces, Point beg, Point end, double tmin, double tmax, int &closest_surface, double &closest_t);
    Point mirrorRay(Point ray, Point normal);
    Point refrRay(Point ray, Point normal, double n1, double n2);
    double computeLighting(std::vector<std::shared_ptr<Object>> &surfaces, std::vector<std::shared_ptr<Light>> &lights, Point p, Point n, Point v, double s);
};


#endif //VIEWER_RAYTRACER_H
