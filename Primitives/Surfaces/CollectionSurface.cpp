//
// Created by Екатерина on 24.10.2021.
//

#include "CollectionSurface.h"
CollectionSurface::CollectionSurface(std::vector<std::shared_ptr<Object>> &v)
{
    objects = v;
}
void CollectionSurface::move(Point mc)
{
    for (auto &obj : objects)
        obj->move(mc);
}
void CollectionSurface::scale(Point sc)
{
    for (auto &obj : objects)
        obj->scale(sc);
}
void CollectionSurface::rotate(Point rc)
{
    for (auto &obj : objects)
        obj->rotate(rc);
}
void CollectionSurface::getIntersection(Point o, Point d, std::vector<double> &t)
{
    for (auto &obj : objects)
        obj->getIntersection(o, d, t);
}
bool CollectionSurface::checkPoint(Point &p)
{
    return true;
}
bool CollectionSurface::isVisible()
{
    return true;
}
bool CollectionSurface::getNormal(Point p, Point &normal)
{
    for (auto &obj : objects)
        if (obj->getNormal(p, normal))
            return true;
    return false;
}