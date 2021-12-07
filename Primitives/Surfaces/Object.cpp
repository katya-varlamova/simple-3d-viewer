//
// Created by Екатерина on 05.10.2021.
//

#include "Object.h"
DrawerColor Object::getColor()
{
    return color;
}
double Object::getShineCoef()
{
    return shine_coef;
}
double Object::getMirrorCoef()
{
    return mirror_coef;
}
double Object::getTranspCoef()
{
    return transp_coef;
}
double Object::getRefrCoef()
{
    return refr_coef;
}
void Object::setColor(DrawerColor c)
{
    color = c;
}
void Object::setMirrorCoef(double c)
{
    mirror_coef = c;
    if (mirror_coef > 1)
        mirror_coef = 1;
}
void Object::setRefrCoef(double c)
{
    refr_coef = c;
}
void Object::setShineCoef(double c)
{
    shine_coef = c;
}
void Object::setTranspCoef(double c)
{
    transp_coef = c;
    if (transp_coef > 1)
        transp_coef = 1;
}
std::string Object::getName()
{
    return name;
}
void Object::setName(std::string &name)
{
    this->name = name;
}
void Object::setCenter(Point c)
{
    this->c = c;
}
Point Object::getCenter()
{
    return c;
}