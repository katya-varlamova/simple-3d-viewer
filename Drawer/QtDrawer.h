//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_QTDRAWER_H
#define VIEW_CPP_QTDRAWER_H
#include <QGraphicsScene>
#include <memory>
#include "Drawer.h"
#include <QPainter>
class QtDrawer : public Drawer{
public:
    QtDrawer(std::shared_ptr<QImage> img, int width, int height);
    virtual void drawPixel(int x, int y, DrawerColor &color) override;
    virtual void getSceneSizes(int &cw, int &ch) override;
//    virtual void clearScene() override;
protected:
    std::shared_ptr<QImage> img;
    int width, height;
    size_t stride;
    uint8_t *pix_ptr;

};


#endif //VIEW_CPP_QTDRAWER_H
