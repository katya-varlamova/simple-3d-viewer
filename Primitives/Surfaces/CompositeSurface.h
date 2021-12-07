//
// Created by Екатерина on 05.10.2021.
//

#ifndef VIEWER_COMPOSITESURFACE_H
#define VIEWER_COMPOSITESURFACE_H

#include "Surface.h"
class CompositeSurface : public Object{
public:
    CompositeSurface(std::shared_ptr<Object> &base, std::shared_ptr<Object> &limiter);
    void getIntersection(Point o, Point d, std::vector<double> &t) override;
    bool getNormal(Point p, Point &normal) override;
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;

    bool checkPoint(Point &p) override;
    bool isVisible() override;
private:
    std::shared_ptr<Object> limiter;
    std::shared_ptr<Object> base;
};


#endif //VIEWER_COMPOSITESURFACE_H
