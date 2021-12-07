//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_DRAWERCREATOR_H
#define VIEW_CPP_DRAWERCREATOR_H

#include "../Drawer.h"
#include <memory>
class DrawerCreator {
public:
    virtual std::shared_ptr<Drawer> createDrawer() = 0;
};


#endif //VIEW_CPP_DRAWERCREATOR_H
