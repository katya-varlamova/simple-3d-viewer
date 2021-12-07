//
// Created by Екатерина on 14.08.2021.
//

#include "PointLight.h"
PointLight::PointLight(Point position)
{
    type = POINT;
    this->position = position;
}
PointLight::PointLight(Point position, double intensity)
{
    type = POINT;
    this->position = position;
    setIntensity(intensity);
}
Point PointLight::getLightDirection(Point p)
{
    return position - p;
}
double PointLight::getIntensityInPoint(Point p, Point n, Point v, double s)
{
    Point direction = position - p;
    double sum_intensity = 0;
    // диффузность
    double n_dot_l = n.scalarMul(direction);
    if (n_dot_l > 0)
        sum_intensity += intensity * n_dot_l / (n.length() * direction.length());

    // зеркальность
    if (s != -1) {
        Point r = n * (2 * n.scalarMul(direction)) - direction;
        double r_dot_v = r.scalarMul(v);
        if (r_dot_v > 0)
            sum_intensity += intensity * pow(r_dot_v / (r.length() * v.length()), s);
    }
    return sum_intensity;
}