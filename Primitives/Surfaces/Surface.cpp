//
// Created by Екатерина on 19.09.2021.
//

#include "Surface.h"
void Surface::initPoly(std::vector<double> coefs)
{
    poly.at(2, 0, 0) = coefs[0];
    poly.at(0, 2, 0) = coefs[1];
    poly.at(0, 0, 2) = coefs[2];
    poly.at(1, 1, 0) = coefs[3];
    poly.at(1, 0, 1) = coefs[4];
    poly.at(0, 1, 1) = coefs[5];
    poly.at(1, 0, 0) = coefs[6];
    poly.at(0, 1, 0) = coefs[7];
    poly.at(0, 0, 1) = coefs[8];
    poly.at(0, 0, 0) = coefs[9];
}
Surface::Surface(std::vector<double> coefs,  int above, bool vis)
: derX(3), derY(3), derZ(3), poly(3)
{
    this->above = above;
    this->vis = vis;
    initPoly(coefs);
    derX = poly.derX();
    derY = poly.derY();
    derZ = poly.derZ();
}
bool Surface::checkPoint(Point &p)
{
    double v = poly.insertValues(p.getX(), p.getY(), p.getZ());
    return above * v > 0;
}
void Surface::getIntersection(Point o, Point d, std::vector<double> &t)
{
    Poly x(2), y(2), z(2);
    x.at(1, 0, 0) = d.getX(); x.at(0, 0, 0) = o.getX();
    y.at(1, 0, 0) = d.getY(); y.at(0, 0, 0) = o.getY();
    z.at(1, 0, 0) = d.getZ(); z.at(0, 0, 0) = o.getZ();
    Poly r = poly.insertCopy(x, y, z);
    std::vector<double> res = {r.at(0, 0, 0),
                               r.at(1, 0, 0),
                               r.at(2, 0, 0)};

    if (res[2] != 0) {
        double discriminant = res[1] * res[1] - 4 * res[2] * res[0];
        if (discriminant < 0) {
            return;
        }
        t.push_back((-res[1] + sqrt(discriminant)) / (2 * res[2]));
        t.push_back((-res[1] - sqrt(discriminant)) / (2 * res[2]));
    }
    else
        t.push_back(-res[0]/ res[1]);
}
bool Surface::getNormal(Point p, Point &normal)
{
    double k = poly.insertValues(p.getX(), p.getY(), p.getZ());
    if (k > 0.0001 || k < -0.0001)
        return false;
    double dx = derX.insertValues(p.getX(), p.getY(), p.getZ());
    double dy = derY.insertValues(p.getX(), p.getY(), p.getZ());
    double dz = derZ.insertValues(p.getX(), p.getY(), p.getZ());

    normal = Point(dx, dy, dz);
    double l = normal.length();
    normal *= 1 / l;
    return true;
}
void Surface::move(Point mc)
{
    Poly x(2), y(2), z(2);
    x.at(1, 0, 0) = 1; x.at(0, 0, 0) = mc.getX();
    y.at(0, 1, 0) = 1; y.at(0, 0, 0) = mc.getY();
    z.at(0, 0, 1) = 1; z.at(0, 0, 0) = mc.getZ();
    poly.insert(x, y, z);
    derX = poly.derX();
    derY = poly.derY();
    derZ = poly.derZ();
}
void Surface::scale(Point sc)
{
    Poly x(2), y(2), z(2);
    x.at(1, 0, 0) = 1 / sc.getX();
    y.at(0, 1, 0) = 1 / sc.getY();
    z.at(0, 0, 1) = 1 / sc.getZ();
    poly.insert(x, y, z);
    derX = poly.derX();
    derY = poly.derY();
    derZ = poly.derZ();
}
void Surface::rotateX(double ang)
{
    Poly x(2), y(2), z(2);
    x.at(1, 0, 0) = 1;
    y.at(0, 1, 0) = cos(ang);
    y.at(0, 0, 1) = sin(ang);
    z.at(0, 1, 0) = -sin(ang);
    z.at(0, 0, 1) = cos(ang);
    poly.insert(x, y, z);
}
void Surface::rotateY(double ang)
{
    Poly x(2), y(2), z(2);
    y.at(0, 1, 0) = 1;

    x.at(1, 0, 0) = cos(ang);
    x.at(0, 0, 1) = sin(ang);

    z.at(1, 0, 0) = -sin(ang);
    z.at(0, 0, 1) = cos(ang);

    poly.insert(x, y, z);

}
void Surface::rotateZ(double ang)
{
    Poly x(2), y(2), z(2);
    z.at(0, 0, 1) = 1;

    x.at(1, 0, 0) = cos(ang);
    x.at(0, 1, 0) = sin(ang);

    y.at(1, 0, 0) = -sin(ang);
    y.at(0, 1, 0) = cos(ang);
    poly.insert(x, y, z);
}
double to_rad(double ang)
{
    return ang * (M_PI / 180.0);
}
void Surface::rotate(Point rc)
{
    if (rc.getX() != 0)
        rotateX(to_rad(rc.getX()));
    if (rc.getY() != 0)
        rotateY(to_rad(rc.getY()));
    if (rc.getZ() != 0)
        rotateZ(to_rad(rc.getZ()));
    derX = poly.derX();
    derY = poly.derY();
    derZ = poly.derZ();

}
bool Surface::isVisible() {
    return vis;
}