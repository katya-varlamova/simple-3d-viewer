//
// Created by Екатерина on 14.08.2021.
//

#include "Light.h"
double Light::getIntensity()
{
    return intensity;
}
void Light::setIntensity(double intensity)
{
    this->intensity = intensity;
}
light_t Light::getType()
{
    return type;
}