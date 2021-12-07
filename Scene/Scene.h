//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_SCENE_H
#define VIEW_CPP_SCENE_H

#include "../Primitives/Point.h"
#include "../Primitives/Surfaces/Object.h"
#include "../Primitives/Surfaces/Surface.h"
#include "../Primitives/Surfaces/CompositeSurface.h"
#include "../Primitives/Light/AmbientLight.h"
#include "../Primitives/Light/PointLight.h"
#include "../Primitives/Light/DirectionalLight.h"
#include "../Primitives/Camera/Camera.h"
#include "../Primitives/Light/PrimitiveLight.h"
#include "../Primitives/Camera//PrimitiveCamera.h"
#include "../Primitives/Surfaces/PrimitiveObject.h"
#include "DrawerAlgo.h"
class Scene {
public:
    Scene(std::shared_ptr<Camera> &camera, std::vector<std::shared_ptr<Light>> &lights, std::vector<std::shared_ptr<Object>> &surfaces);
    void setDrawerAlgo(std::shared_ptr<DrawerAlgo> &drawerAlgo);
    void draw(std::shared_ptr<Drawer> &grDrawer);
    std::vector<std::shared_ptr<Primitive>>::const_iterator begin();
    std::vector<std::shared_ptr<Primitive>>::const_iterator end();
private:
    std::shared_ptr<DrawerAlgo> drawerAlgo;
    std::vector<std::shared_ptr<Object>> surfaces;
    std::vector<std::shared_ptr<Light>> lights;
    std::shared_ptr<Camera> camera;
    std::vector<std::shared_ptr<Primitive>> primitives;
};


#endif //VIEW_CPP_SCENE_H
