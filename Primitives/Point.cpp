//
// Created by Екатерина on 14.08.2021.
//

#include "Point.h"
Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Point Point::operator+(const Point &point) const
{
    Point res = Point(this->x + point.x,
                      this->y + point.y,
                      this->z + point.z);
    return res;
}
Point &Point::operator+=(const Point &point)
{
    this->x += point.x;
    this->y += point.y;
    this->z += point.z;
    return *this;
}
Point Point::operator-(const Point &point) const
{
    Point res = Point(this->x - point.x,
                      this->y - point.y,
                      this->z - point.z);
    return res;
}
Point &Point::operator-=(const Point &point)
{
    this->x -= point.x;
    this->y -= point.y;
    this->z -= point.z;
    return *this;
}
Point Point::operator*(const Point &point) const
{
    Point res = Point(this->x * point.x,
                      this->y * point.y,
                      this->z * point.z);
    return res;
}
Point &Point::operator*=(const Point &point)
{
    this->x *= point.x;
    this->y *= point.y;
    this->z *= point.z;
    return *this;
}
Point Point::operator*(double elem) const
{
    Point res = Point(this->x * elem,
                      this->y * elem,
                      this->z * elem);
    return res;
}
Point& Point::operator*=(double elem)
{
    this->x *= elem;
    this->y *= elem;
    this->z *= elem;
    return *this;
}
double Point::scalarMul(Point p)
{
    Point res = *this * p;
    return res.x + res.y + res.z;
}
double Point::length()
{
    return sqrt(scalarMul(*this));
}
double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
double Point::getZ()
{
    return z;
}
void Point::setX(double x) {
    this->x = x;
}
void Point::setY(double y) {
    this->y = y;
}
void Point::setZ(double z) {
    this->z = z;
}
Point Point::operator-() const
{
    return Point(-x, -y, -z);
}
Point Point::neg()
{
    return Point(-x, -y, -z);
}
std::istream& operator>> (std::istream &in, Point &point)
{
    in >> point.x;
    in >> point.y;
    in >> point.z;
    return in;
}
std::ostream& operator<< (std::ostream &out, const Point &point)
{
    out << point.x << " " << point.y << " " << point.z << "\n";
    return out;
}

