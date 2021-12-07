//
// Created by Екатерина on 29.10.2021.
//

#include "DrawerColor.h"
DrawerColor::DrawerColor(int r, int g, int b)
{
    this->r = r > 255 ? 255 : r;
    this->g = g > 255 ? 255 : g;
    this->b = b > 255 ? 255 : b;
}
DrawerColor DrawerColor::operator+(const DrawerColor &color)
{
    return DrawerColor((r + color.r) > 255 ? 255 : r + color.r,
                       (g + color.g) > 255 ? 255 : g + color.g,
                       (b + color.b) > 255 ? 255 : b + color.b);
}
DrawerColor & DrawerColor::operator+=(const DrawerColor &color)
{
    *this = *this + color;
    return *this;
}
DrawerColor DrawerColor::operator*(const DrawerColor &color)
{
    return DrawerColor((r * color.r) > 255 ? 255 : r * color.r,
                       (g * color.g) > 255 ? 255 : g * color.g,
                       (b * color.b) > 255 ? 255 : b * color.b);
}
DrawerColor & DrawerColor::operator*=(const DrawerColor &color)
{
    *this = *this * color;
    return *this;
}
DrawerColor DrawerColor::operator*(double elem)
{
    return DrawerColor(r * elem > 255 ? 255 : r * elem,
                       g * elem > 255 ? 255 : g * elem,
                       b * elem > 255 ? 255 : b * elem);
}
DrawerColor & DrawerColor::operator*=(double elem)
{
    *this = *this * elem;
    return *this;
}
int DrawerColor::getR()
{
    return r;
}
int DrawerColor::getG()
{
    return g;
}
int DrawerColor::getB()
{
    return b;
}