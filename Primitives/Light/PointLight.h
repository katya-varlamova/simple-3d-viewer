//
// Created by Екатерина on 14.08.2021.
//

#ifndef VIEWER_POINTLIGHT_H
#define VIEWER_POINTLIGHT_H

#include "Light.h"
class PointLight : public Light
{
public:
    PointLight(Point position);
    PointLight(Point position, double intensity);
    virtual Point getLightDirection(Point p) override;
    virtual double getIntensityInPoint(Point p, Point n, Point v, double s) override;
protected:
    Point position;
};


#endif //VIEWER_POINTLIGHT_H
