//
// Created by Екатерина on 05.11.2021.
//

#ifndef VIEW_CPP_TORUS_H
#define VIEW_CPP_TORUS_H
#include <cmath>
#include "Object.h"
#include "Poly.h"
#include "qsolver.h"
class Torus : public Object{
public:
    Torus(double R, double r, int above, bool vis);
    bool getNormal(Point p, Point &normal) override;
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;
    void getIntersection(Point o, Point d, std::vector<double> &t) override;
    bool checkPoint(Point &p) override;
    bool isVisible() override;
private:
    void initPoly(double R, double r);
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


#endif //VIEW_CPP_TORUS_H
