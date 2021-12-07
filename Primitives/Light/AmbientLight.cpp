//
// Created by Екатерина on 14.08.2021.
//

#include "AmbientLight.h"
AmbientLight::AmbientLight()
{
    type = AMBIENT;
}
AmbientLight::AmbientLight(double intensity)
{
    type = AMBIENT;
    setIntensity(intensity);
}
Point AmbientLight::getLightDirection(Point p)
{
    return Point(0, 0, 0);
}
double AmbientLight::getIntensityInPoint(Point p, Point n, Point v, double s)
{
    return intensity;
}