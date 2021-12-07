//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_DRAWERALGO_H
#define VIEW_CPP_DRAWERALGO_H

#include "../Drawer/Drawer.h"
#include "../Primitives/Camera/Camera.h"
#include "../Primitives/Light/Light.h"
#include "../Primitives/Surfaces/Object.h"

class DrawerAlgo {
public:
    virtual void draw(std::shared_ptr<Drawer> &drawer, std::vector<std::shared_ptr<Light>> &lights, std::vector<std::shared_ptr<Object>>  &surfaces, std::shared_ptr<Camera> &cam) = 0;
};


#endif //VIEW_CPP_DRAWERALGO_H
