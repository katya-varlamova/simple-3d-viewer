//
// Created by Екатерина on 05.10.2021.
//

#include "CompositeSurface.h"
CompositeSurface::CompositeSurface(std::shared_ptr<Object> &base, std::shared_ptr<Object> &limiter)
{
    this->base = base;
    this->limiter = limiter;
}
void CompositeSurface::getIntersection(Point o, Point d, std::vector<double> &t) {
    std::vector<double> tmp;
    base->getIntersection(o, d, tmp);
    for (int j = 0; j < tmp.size(); j++)
    {
        Point p = o + d * tmp[j];
        if (limiter->checkPoint(p))
            t.push_back(tmp[j]);
    }
    if (limiter->isVisible())
        limiter->getIntersection(o, d, t);
}
bool CompositeSurface::checkPoint(Point &p)
{
    bool vl = limiter->checkPoint(p);
    bool vb = base->checkPoint(p);
    return  vl && vb || !vl;
}
bool CompositeSurface::getNormal(Point p, Point &normal)
{
    Point n;
    if (base->getNormal(p, n))
    {
        normal = n;
        return true;
    }
    if (limiter->getNormal(p, n))
    {
        normal = n;
        return true;
    }
    return false;
}
bool CompositeSurface::isVisible()
{
    return limiter->isVisible() || base->isVisible();
}
void CompositeSurface::scale(Point sc)
{
    limiter->scale(sc);
    base->scale(sc);
}
void CompositeSurface::move(Point mc)
{
    limiter->move(mc);
    base->move(mc);
}
void CompositeSurface::rotate(Point rc)
{
    limiter->rotate(rc);
    base->rotate(rc);
}