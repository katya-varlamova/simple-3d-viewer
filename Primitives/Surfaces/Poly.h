//
// Created by Екатерина on 19.09.2021.
//

#ifndef VIEWER_POLY_H
#define VIEWER_POLY_H
#include <vector>
#include <memory>
#include <stdlib.h>
class node
{
public:
    node() = default;
    node(int x, int y, int z, double *ptr)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->elem = ptr;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }
    double & getElem()
    {
        return *elem;
    }
private:
    int x, y, z;
    double *elem;
};
class Poly {
public:
    Poly(int maxdeg);
    Poly(Poly &poly);
    Poly(Poly &&poly) noexcept;
    Poly derX();
    Poly derY();
    Poly derZ();
    double getElem(int xi, int yi, int zi);
    double &at(int xi, int yi, int zi);
    void insert(Poly x, Poly y, Poly z);
    Poly insertCopy(Poly x, Poly y, Poly z);
    double insertValues(double x, double y, double z);

    Poly operator+(Poly Poly);
    Poly &operator+=(Poly Poly);

    Poly operator-(Poly Poly);
    Poly &operator-=(Poly Poly);

    Poly operator*(Poly Poly);
    Poly &operator*=(Poly Poly);
    Poly &operator*=(double elem);
    Poly &operator=(Poly &poly);
    Poly &operator=(Poly &&poly) noexcept;
    void fill(double el);
//    Poly operator*(double elem);
//    Poly &operator*=(double elem);
    int getDeg();
    void print();

protected:
    double coefs[7][7][7];

    int maxdeg;
};


#endif //VIEWER_POLY_H
