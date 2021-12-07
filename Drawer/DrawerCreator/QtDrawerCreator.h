//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_QTDRAWERCREATOR_H
#define VIEW_CPP_QTDRAWERCREATOR_H

#include <QGraphicsScene>
#include "../QtDrawer.h"
#include "DrawerCreator.h"
class QtDrawerCreator : public DrawerCreator{
public:
    QtDrawerCreator(std::shared_ptr<QImage> img, int width, int height);
    virtual std::shared_ptr<Drawer> createDrawer() override;

protected:
    std::shared_ptr<QImage> img;
    int width, height;
};


#endif //VIEW_CPP_QTDRAWERCREATOR_H
