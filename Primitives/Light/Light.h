//
// Created by Екатерина on 14.08.2021.
//

#ifndef VIEWER_LIGHT_H
#define VIEWER_LIGHT_H
#include "../Point.h"

typedef enum
{
    AMBIENT, POINT, DIRECTIONAL
} light_t;
class Light
{
public:
    Light() = default;
    double getIntensity();
    light_t getType();
    void setIntensity(double intensity);
    virtual Point getLightDirection(Point p) = 0;
    virtual double getIntensityInPoint(Point p, Point n, Point v, double s) = 0;

protected:
    light_t type;
    double intensity;
};



#endif //VIEWER_LIGHT_H
