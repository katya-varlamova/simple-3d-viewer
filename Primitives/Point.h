//
// Created by Екатерина on 14.08.2021.
//

#ifndef VIEWER_POINT_H
#define VIEWER_POINT_H
#include <cmath>
#include <iostream>
class Point
{
public:
    Point() = default;
    Point(double x, double y, double z);

    double getX();
    double getY();
    double getZ();

    void setX(double);
    void setY(double);
    void setZ(double);

    Point operator+(const Point &point) const;
    Point&operator+=(const Point &point);

    Point operator-(const Point &point) const;
    Point&operator-=(const Point &point);

    Point operator*(const Point &point) const;
    Point&operator*=(const Point &point);
    Point operator*(double elem) const;
    Point&operator*=(double elem);
    double scalarMul(Point p);
    double length();
    Point operator-() const;
    Point neg();
    friend std::ostream& operator<< (std::ostream &out, const Point &point);
    friend std::istream& operator>> (std::istream &in, Point &point);
protected:
    double x, y, z;
};



#endif //VIEWER_POINT_H
