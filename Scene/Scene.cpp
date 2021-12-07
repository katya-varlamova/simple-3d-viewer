//
// Created by Екатерина on 25.10.2021.
//

#include "Scene.h"
Scene::Scene(std::shared_ptr<Camera> &camera, std::vector<std::shared_ptr<Light>> &lights, std::vector<std::shared_ptr<Object>> &surfaces)
{
    this->camera = camera;
    this->lights = lights;
    this->surfaces = surfaces;
    for (auto &l : lights)
        primitives.push_back(std::shared_ptr<Primitive>(new PrimitiveLight(l)));
    for (auto &s : surfaces)
        primitives.push_back(std::shared_ptr<Primitive>(new PrimitiveObject(s)));
    primitives.push_back(std::shared_ptr<Primitive>(new PrimitiveCamera(camera)));
}
std::vector<std::shared_ptr<Primitive>>::const_iterator Scene::begin()
{
    return primitives.begin();
}
std::vector<std::shared_ptr<Primitive>>::const_iterator Scene::end()
{
    return primitives.end();
}
void Scene::setDrawerAlgo(std::shared_ptr<DrawerAlgo> &drawerAlgo)
{
    this->drawerAlgo = drawerAlgo;
}
void Scene::draw(std::shared_ptr<Drawer> &grDrawer)
{
    drawerAlgo->draw(grDrawer, lights, surfaces, camera);
}