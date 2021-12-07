//
// Created by Екатерина on 05.11.2021.
//

#include "Torus.h"

void Torus::initPoly(double R, double r)
{
    double RR = R * R;
    double rr = r * r;
    poly.at(4, 0, 0) = 1;
    poly.at(0, 4, 0) = 1;
    poly.at(0, 0, 4) = 1;

    poly.at(2, 2, 0) = 2;
    poly.at(2, 0, 2) = 2;
    poly.at(0, 2, 2) = 2;

    poly.at(2, 0, 0) = -2 * (RR + rr);
    poly.at(0, 2, 0) = -2 * (RR + rr) + 4 * RR;
    poly.at(0, 0, 2) = -2 * (RR + rr);

    poly.at(0, 0, 0) = (RR - rr) * (RR - rr);
}
Torus::Torus(double R, double r, int above, bool vis) : derX(5), derY(5), derZ(5), poly(5)
{
    this->above = above;
    this->vis = vis;
    initPoly(R, r);
    derX = poly.derX();
    derY = poly.derY();
    derZ = poly.derZ();
}
bool Torus::checkPoint(Point &p)
{
    double v = poly.insertValues(p.getX(), p.getY(), p.getZ());
    return above * v > 0;
}
void Torus::getIntersection(Point o, Point d, std::vector<double> &t)
{
    Poly x(2), y(2), z(2);
    x.at(1, 0, 0) = d.getX(); x.at(0, 0, 0) = o.getX();
    y.at(1, 0, 0) = d.getY(); y.at(0, 0, 0) = o.getY();
    z.at(1, 0, 0) = d.getZ(); z.at(0, 0, 0) = o.getZ();
    Poly r = poly.insertCopy(x, y, z);
    double mas[4];
    int n = SolveP4(mas, r.at(3, 0, 0) / r.at(4, 0, 0),
                    r.at(2, 0, 0) / r.at(4, 0, 0),
                    r.at(1, 0, 0) / r.at(4, 0, 0),
                    r.at(0, 0, 0) / r.at(4, 0, 0));
    for (int i = 0; i < n; i++)
        t.push_back(mas[i]);
}
bool Torus::getNormal(Point p, Point &normal)
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
void Torus::move(Point mc)
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
void Torus::scale(Point sc)
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
void Torus::rotateX(double ang)
{
    Poly x(2), y(2), z(2);
    x.at(1, 0, 0) = 1;
    y.at(0, 1, 0) = cos(ang);
    y.at(0, 0, 1) = sin(ang);
    z.at(0, 1, 0) = -sin(ang);
    z.at(0, 0, 1) = cos(ang);
    poly.insert(x, y, z);
}
void Torus::rotateY(double ang)
{
    Poly x(2), y(2), z(2);
    y.at(0, 1, 0) = 1;

    x.at(1, 0, 0) = cos(ang);
    x.at(0, 0, 1) = sin(ang);

    z.at(1, 0, 0) = -sin(ang);
    z.at(0, 0, 1) = cos(ang);

    poly.insert(x, y, z);

}
void Torus::rotateZ(double ang)
{
    Poly x(2), y(2), z(2);
    z.at(0, 0, 1) = 1;

    x.at(1, 0, 0) = cos(ang);
    x.at(0, 1, 0) = sin(ang);

    y.at(1, 0, 0) = -sin(ang);
    y.at(0, 1, 0) = cos(ang);
    poly.insert(x, y, z);
}
static double to_rad(double ang)
{
    return ang * (M_PI / 180.0);
}
void Torus::rotate(Point rc)
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
bool Torus::isVisible() {
    return vis;
}