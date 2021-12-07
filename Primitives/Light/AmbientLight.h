//
// Created by Екатерина on 14.08.2021.
//

#ifndef VIEWER_AMBIENTLIGHT_H
#define VIEWER_AMBIENTLIGHT_H
#include "Light.h"
class AmbientLight : public Light
{
public:
    AmbientLight();
    explicit AmbientLight(double intensity);
    virtual Point getLightDirection(Point p) override;
    virtual double getIntensityInPoint(Point p, Point n, Point v, double s) override;
};


#endif //VIEWER_AMBIENTLIGHT_H
