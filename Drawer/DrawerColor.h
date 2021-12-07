//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_DRAWERCOLOR_H
#define VIEW_CPP_DRAWERCOLOR_H


class DrawerColor {
public:
    DrawerColor() = default;
    DrawerColor(int r, int g, int b);

    DrawerColor operator+(const DrawerColor &color);
    DrawerColor &operator+=(const DrawerColor &color);

    DrawerColor operator*(const DrawerColor &color);
    DrawerColor &operator*=(const DrawerColor &color);
    DrawerColor operator*(double elem);
    DrawerColor &operator*=(double elem);

    int getR();
    int getG();
    int getB();


protected:
    int r, g, b;

};


#endif //VIEW_CPP_DRAWERCOLOR_H
