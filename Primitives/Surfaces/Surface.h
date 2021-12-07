//
// Created by Екатерина on 19.09.2021.
//

#ifndef VIEWER_SURFACE_H
#define VIEWER_SURFACE_H
#include "QColor"
#include "../Point.h"
#include <vector>
#include "Poly.h"
#include <iostream>
#include "Object.h"
class Surface : public Object {
public:
    Surface(std::vector<double> coefs, int above, bool vis);
    bool getNormal(Point p, Point &normal) override;
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;
    void getIntersection(Point o, Point d, std::vector<double> &t) override;
    bool checkPoint(Point &p) override;
    bool isVisible() override;
private:
    void initPoly(std::vector<double> coefs);
    void rotateZ(double ang);
    void rotateY(double ang);
    void rotateX(double ang);
    int above;
    bool vis;
    Poly poly;
    Poly derX;
    Poly derY;
    Poly derZ;
};


#endif //VIEWER_SURFACE_H
