//
// Created by Екатерина on 24.10.2021.
//

#ifndef VIEW_CPP_COLLECTIONSURFACE_H
#define VIEW_CPP_COLLECTIONSURFACE_H

#include <vector>
#include "Object.h"
class CollectionSurface : public Object{
public:
    explicit CollectionSurface(std::vector<std::shared_ptr<Object>> &v);
    void getIntersection(Point o, Point d, std::vector<double> &t) override;
    bool getNormal(Point p, Point &normal) override;
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;

    bool checkPoint(Point &p) override;
    bool isVisible() override;
private:
    std::vector<std::shared_ptr<Object>> objects;
};


#endif //VIEW_CPP_COLLECTIONSURFACE_H
