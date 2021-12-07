//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_DRAWER_H
#define VIEW_CPP_DRAWER_H

#include "DrawerColor.h"
class Drawer {
public:
    virtual void drawPixel(int x, int y, DrawerColor &color) = 0;
    virtual void getSceneSizes(int &cw, int &ch) = 0;
//    virtual void clearScene() = 0;
};


#endif //VIEW_CPP_DRAWER_H
