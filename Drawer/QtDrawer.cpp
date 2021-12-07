//
// Created by Екатерина on 29.10.2021.
//

#include "QtDrawer.h"
QtDrawer::QtDrawer(std::shared_ptr<QImage> img, int width, int height)
{
    this->img = img;
    this->width = width;
    this->height = height;
    stride = img->bytesPerLine();
    pix_ptr = img->scanLine(0);
}
void QtDrawer::drawPixel(int x, int y, DrawerColor &color)
{
    x += width / 2;
    y += height / 2;

    uint8_t *pix = pix_ptr + y * stride + 4 * x;
    pix[0] = color.getB(), pix[1] = color.getG(), pix[2] = color.getR(), pix[3] = 255;
}
void QtDrawer::getSceneSizes(int &cw, int &ch)
{
    cw = width;
    ch = height;
}