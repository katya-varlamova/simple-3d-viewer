//
// Created by Екатерина on 19.09.2021.
//

#include "Poly.h"
void Poly::fill(double el)
{
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                coefs[i][j][k] = 0;
}
Poly::Poly(int maxdeg){
    this->maxdeg = maxdeg;
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                coefs[i][j][k] = 0;
}
Poly::Poly(Poly &poly)
{
    fill(0);
    maxdeg = poly.maxdeg;
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                coefs[i][j][k] = poly.coefs[i][j][k];
}
Poly::Poly(Poly &&poly) noexcept
{
    fill(0);
    maxdeg = poly.maxdeg;
    for (int i = 0; i < poly.maxdeg; i++)
        for (int j = 0; j < poly.maxdeg; j++)
            for (int k = 0; k < poly.maxdeg; k++)
                coefs[i][j][k] = poly.coefs[i][j][k];
}
Poly &Poly::operator=(Poly &poly)
{
    fill(0);
    maxdeg = poly.maxdeg;
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                coefs[i][j][k] = poly.coefs[i][j][k];
    return *this;
}
Poly &Poly::operator=(Poly &&poly) noexcept
{
    fill(0);
    maxdeg = poly.maxdeg;
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                coefs[i][j][k] = poly.coefs[i][j][k];
    return *this;
}
Poly Poly::derX()
{
    Poly p(maxdeg);
    p.fill(0);
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                if (i != 0)
                    p.coefs[i - 1][j][k] = coefs[i][j][k] * i;
    return p;
}
Poly Poly::derY()
{
    Poly p(maxdeg);
    p.fill(0);
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                if (j != 0)
                    p.coefs[i][j - 1][k] = coefs[i][j][k] * j;
    return p;
}
Poly Poly::derZ()
{
    Poly p(maxdeg);
    p.fill(0);
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                if (k != 0)
                    p.coefs[i][j][k - 1] = coefs[i][j][k] * k;
    return p;
}
double Poly::getElem(int xi, int yi, int zi)
{
    if (xi >= maxdeg || yi >= maxdeg || zi >= maxdeg)
        return 0;
    return coefs[xi][yi][zi];
}
int Poly::getDeg()
{
    return maxdeg;
}
double &Poly::at(int xi, int yi, int zi)
{
    return coefs[xi][yi][zi];
}
Poly Poly::operator*(Poly poly)
{
    Poly res(maxdeg + poly.getDeg() - 1);
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
            {
                if (coefs[i][j][k] == 0)
                    continue;
                for (int ip = 0; ip < poly.getDeg(); ip++)
                    for (int jp = 0; jp < poly.getDeg(); jp++)
                        for (int kp = 0; kp < poly.getDeg(); kp++)
                        {
                            if (poly.coefs[ip][jp][kp] == 0)
                                continue;
                            res.at(i + ip, j + jp, k + kp) += coefs[i][j][k] * poly.coefs[ip][jp][kp];
                        }
    }

    return res;
}
Poly &Poly::operator*=(Poly poly)
{
    *this = *this * poly;
    return *this;
}
Poly &Poly::operator*=(double elem)
{
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                coefs[i][j][k] *= elem;
    return *this;
}
Poly Poly::operator+(Poly poly)
{
    int md = std::max(poly.maxdeg, maxdeg);
    Poly res(md);
    for (int i = 0; i < md; i++) {
        for (int j = 0; j < md; j++) {
            for (int k = 0; k < md; k++) {
                res.at(i, j, k) = getElem(i, j, k) + poly.getElem(i, j, k);
            }
        }
    }
    return res;
}
Poly &Poly::operator+=(Poly poly)
{
    *this = *this + poly;
    return *this;
}
double Poly::insertValues(double x, double y, double z)
{
    double res = 0;
    double r;
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
            {
                if (coefs[i][j][k] != 0)
                {
                    r = 1;
                    if (i != 0) {
                        r = x;
                        for (int ni = 0; ni < i - 1; ni++)
                            r *= x;
                        for (int nj = 0; nj < j; nj++)
                            r *= y;
                        for (int nk = 0; nk < k; nk++)
                            r *= z;
                    } else if (j != 0)
                    {
                        r = y;
                        for (int nj = 0; nj < j - 1; nj++)
                            r *= y;
                        for (int nk = 0; nk < k; nk++)
                            r *= z;
                    }
                    else if (k != 0)
                    {
                        r = z;
                        for (int nk = 0; nk < k - 1; nk++)
                            r *= z;
                    }
                    r *= coefs[i][j][k];
                    res += r;
                }
    }
//    double res = 0;
//    double r;
//    double rx, ry, rz;
//    rx = 1;
//    for (int i = 0; i < maxdeg; i++) {
//        ry = 1;
//        for (int j = 0; j < maxdeg; j++) {
//            rz = 1;
//            for (int k = 0; k < maxdeg; k++) {
//                if (coefs[i][j][k] != 0)
//                {
//                    r = rx * ry * rz * coefs[i][j][k];
//                    res += r;
//                }
//                rz *= z;
//            }
//            ry *= y;
//        }
//        rx *= x;
//    }
    return res;
}
Poly Poly::insertCopy(Poly x, Poly y, Poly z)
{
    Poly res( (maxdeg - 1) * (std::max(std::max(x.maxdeg, y.maxdeg), z.maxdeg) - 1) + 1);
    Poly r((maxdeg - 1) * (std::max(std::max(x.maxdeg, y.maxdeg), z.maxdeg) - 1) + 1);
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
            {
                if (coefs[i][j][k] != 0)
                {
                    r.fill(0);
                    r.at(0,0, 0) = 1;
                    if (i != 0) {
                        r = x;
                        for (int ni = 0; ni < i - 1; ni++)
                            r *= x;
                        for (int nj = 0; nj < j; nj++)
                            r *= y;
                        for (int nk = 0; nk < k; nk++)
                            r *= z;
                    } else if (j != 0)
                    {
                        r = y;
                        for (int nj = 0; nj < j - 1; nj++)
                            r *= y;
                        for (int nk = 0; nk < k; nk++)
                            r *= z;
                    }
                    else if (k != 0)
                    {
                        r = z;
                        for (int nk = 0; nk < k - 1; nk++)
                            r *= z;
                    }
                    r *= coefs[i][j][k];
                    res += r;
                }
            }
    return res;
}
void Poly::insert(Poly x, Poly y, Poly z)
{
    Poly res = insertCopy(x, y, z);
    *this = res;
}
#include <iostream>
void Poly::print()
{
    for (int i = 0; i < maxdeg; i++)
        for (int j = 0; j < maxdeg; j++)
            for (int k = 0; k < maxdeg; k++)
                std::cout << coefs[i][j][k] << " ";
    std::cout << "\n";
}
//Poly::Poly(std::vector<double> coefs)
//{
//    this->coefs = coefs;
//}
//double & Poly::operator[](int ind)
//{
//    return coefs[ind];
//}
//int Poly::getDeg()
//{
//    return coefs.size();
//}
//Poly Poly::operator+(Poly poly)
//{
//    std::vector<double> res;
//    bool thismax = getDeg() > poly.getDeg();
//    int minDeg = std::min(getDeg(), poly.getDeg());
//    for (int i = 0 ; i < minDeg; i++)
//        res.push_back(coefs[i] + poly[i]);
//    if (thismax) {
//        for (int i = minDeg; i < getDeg(); i++)
//            res.push_back(coefs[i]);
//    } else {
//        for (int i = minDeg; i < poly.getDeg(); i++)
//            res.push_back(poly[i]);
//    }
//    return Poly(res);
//}
//Poly &Poly::operator+=(Poly poly)
//{
//    bool thismax = getDeg() > poly.getDeg();
//    int minDeg = std::min(getDeg(), poly.getDeg());
//    for (int i = 0 ; i < minDeg; i++)
//        coefs[i] += poly[i];
//    if (!thismax) {
//        for (int i = minDeg; i < poly.getDeg(); i++)
//            coefs.push_back(poly[i]);
//    }
//    return *this;
//}
//Poly Poly::operator-(Poly poly)
//{
//    std::vector<double> res;
//    bool thismax = getDeg() > poly.getDeg();
//    int minDeg = std::min(getDeg(), poly.getDeg());
//    for (int i = 0 ; i < minDeg; i++)
//        res.push_back(coefs[i] - poly[i]);
//    if (thismax) {
//        for (int i = minDeg; i < getDeg(); i++)
//            res.push_back(coefs[i]);
//    } else {
//        for (int i = minDeg; i < poly.getDeg(); i++)
//            res.push_back(-poly[i]);
//    }
//    return Poly(res);
//}
//Poly &Poly::operator-=(Poly poly)
//{
//    bool thismax = getDeg() > poly.getDeg();
//    int minDeg = std::min(getDeg(), poly.getDeg());
//    for (int i = 0 ; i < minDeg; i++)
//        coefs[i] -= poly[i];
//    if (!thismax) {
//        for (int i = minDeg; i < poly.getDeg(); i++)
//            coefs.push_back(-poly[i]);
//    }
//    return *this;
//}
//Poly Poly::operator*(Poly poly)
//{
//    std::vector<double> res;
//    for (int i = 0; i < poly.getDeg() + getDeg() - 1; i++)
//        res.push_back(0);
//    for (int i = 0 ; i < getDeg(); i++)
//        for (int j = 0; j < poly.getDeg(); j++)
//            res[i + j] += coefs[i] * poly[j];
//    return Poly(res);
//}
//Poly &Poly::operator*=(Poly poly)
//{
//    std::vector<double> res;
//    for (int i = 0; i < poly.getDeg() + getDeg() - 1; i++)
//        res.push_back(0);
//    for (int i = 0 ; i < getDeg(); i++) {
//        for (int j = 0; j < poly.getDeg(); j++)
//            res[i + j] += coefs[i] * poly[j];
//    }
//    coefs = res;
//    return *this;
//}
//Poly Poly::operator*(double elem)
//{
//    std::vector<double> res;
//    for (int i = 0; i < getDeg(); i++)
//        res.push_back(elem * coefs[i]);
//    return Poly(res);
//}
//Poly &Poly::operator*=(double elem) {
//    for (int i = 0; i < getDeg(); i++)
//        coefs[i] = elem * coefs[i];
//    return *this;
//}