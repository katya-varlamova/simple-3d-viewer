//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_SCENELOADER_H
#define VIEW_CPP_SCENELOADER_H

#include "../Scene/Scene.h"
#include "LightsLoader.h"
#include "ObjectsLoader.h"
#include "CameraLoader.h"
class SceneLoader {
public:
    SceneLoader(std::shared_ptr<ObjectsLoader> &ol, std::shared_ptr<CameraLoader> &cl, std::shared_ptr<LightsLoader> &ll);
    void open();
    std::shared_ptr<Scene> load();
    void close();
protected:
    std::shared_ptr<ObjectsLoader> ol;
    std::shared_ptr<CameraLoader> cl;
    std::shared_ptr<LightsLoader> ll;
};


#endif //VIEW_CPP_SCENELOADER_H
