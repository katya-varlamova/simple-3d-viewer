//
// Created by Екатерина on 14.08.2021.
//

#ifndef VIEWER_DIRECTIONALLIGHT_H
#define VIEWER_DIRECTIONALLIGHT_H
#include "Light.h"

class DirectionalLight : public Light
{
public:
    DirectionalLight(Point direction);
    DirectionalLight(Point direction, double intensity);
    virtual Point getLightDirection(Point p) override;
    virtual double getIntensityInPoint(Point p, Point n, Point v, double s) override;
protected:
    Point direction;
};


#endif //VIEWER_DIRECTIONALLIGHT_H
