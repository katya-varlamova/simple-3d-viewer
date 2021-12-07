//
// Created by Екатерина on 29.10.2021.
//

#include "QtDrawerCreator.h"

QtDrawerCreator::QtDrawerCreator(std::shared_ptr<QImage> img, int width, int height)
{
    this->img = img;
    this->width = width;
    this->height = height;
}
std::shared_ptr<Drawer> QtDrawerCreator::createDrawer()
{
    return std::shared_ptr<Drawer>(new QtDrawer(img, width, height));
}