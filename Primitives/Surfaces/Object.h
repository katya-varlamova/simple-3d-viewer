//
// Created by Екатерина on 05.10.2021.
//

#ifndef VIEWER_OBJECT_H
#define VIEWER_OBJECT_H

#include "../Point.h"
#include <vector>
#include <memory>
#include "../../Drawer/DrawerColor.h"
class Object {
public:
    Object() = default;
    virtual bool getNormal(Point p, Point &normal)  = 0;
    virtual void move(Point mc) = 0;
    virtual void scale(Point sc) = 0;
    virtual void rotate(Point rc) = 0;
    virtual void getIntersection(Point o, Point d, std::vector<double> &t) = 0;
    std::string getName();
    DrawerColor getColor();
    double getShineCoef();
    double getMirrorCoef();
    double getTranspCoef();
    double getRefrCoef();
    Point getCenter();

    void setName(std::string &name);
    void setColor(DrawerColor c);
    void setShineCoef(double c);
    void setMirrorCoef(double c);
    void setTranspCoef(double c);
    void setRefrCoef(double c);
    void setCenter(Point c);

    virtual bool checkPoint(Point &p) = 0;
    virtual bool isVisible() = 0;

protected:
    std::string name = "";
    DrawerColor color;
    double shine_coef = -1;
    double mirror_coef = 0;
    double transp_coef = 0;
    double refr_coef = 1;
    Point c;
};


#endif //VIEWER_OBJECT_H
