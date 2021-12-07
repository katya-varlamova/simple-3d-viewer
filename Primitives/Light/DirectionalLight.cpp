//
// Created by Екатерина on 14.08.2021.
//

#include "DirectionalLight.h"
DirectionalLight::DirectionalLight(Point direction)
{
    type = DIRECTIONAL;
    this->direction = direction;
}
DirectionalLight::DirectionalLight(Point direction, double intensity)
{
    type = DIRECTIONAL;
    this->direction = direction;
    setIntensity(intensity);
}
Point DirectionalLight::getLightDirection(Point p)
{
    return direction;
}
double DirectionalLight::getIntensityInPoint(Point p, Point n, Point v, double s)
{
    double sum_intensity = 0;
    // диффузность
    double n_dot_l = n.scalarMul(direction);
    if (n_dot_l > 0)
        sum_intensity += intensity * n_dot_l / (n.length() * direction.length());

    // зеркальность
    if (s != -1) {
        Point r = n * (2 * n_dot_l) - direction;
        double r_dot_v = r.scalarMul(v);
        if (r_dot_v > 0)
            sum_intensity += intensity * pow(r_dot_v / (r.length() * v.length()), s);
    }
    return sum_intensity;
}