//
// Created by Екатерина on 29.10.2021.
//
#include "SceneLoader.h"
SceneLoader::SceneLoader(std::shared_ptr<ObjectsLoader> &ol, std::shared_ptr<CameraLoader> &cl,
                         std::shared_ptr<LightsLoader> &ll) {
    this->ol = ol;
    this->cl = cl;
    this->ll = ll;
}
void SceneLoader::open()
{
    ol->open();
    cl->open();
    ll->open();
}
void SceneLoader::close()
{
    ol->close();
    cl->close();
    ll->close();
}
std::shared_ptr<Scene> SceneLoader::load()
{
    std::vector<std::shared_ptr<Object>> objects = ol->load();
    std::shared_ptr<Camera> cam = cl->load();
    std::vector<std::shared_ptr<Light>> lights = ll->load();
    return std::shared_ptr<Scene> (new Scene(cam, lights, objects));
}