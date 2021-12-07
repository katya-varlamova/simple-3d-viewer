//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_FILELIGHTSLOADER_H
#define VIEW_CPP_FILELIGHTSLOADER_H

#include <fstream>
#include <value.h>
#include "../LightsLoader.h"
#include "../../Primitives/Light/AmbientLight.h"
#include "../../Primitives/Light/DirectionalLight.h"
#include "../../Primitives/Light/PointLight.h"
class FileLightsLoader : public LightsLoader{
public:
    explicit FileLightsLoader(std::string filename);
    void open() override;
    void close() override;
    std::vector<std::shared_ptr<Light>> load() override;
private:
    std::string filename;
    std::ifstream in;
    bool opened = false;
    Json::Value root;
};


#endif //VIEW_CPP_FILELIGHTSLOADER_H
