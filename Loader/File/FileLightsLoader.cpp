//
// Created by Екатерина on 25.10.2021.
//

#include <json.h>
#include "FileLightsLoader.h"
FileLightsLoader::FileLightsLoader(std::string filename)
{
    this->filename = filename;
}
void FileLightsLoader::open()
{
    in.open(filename);
    opened = true;
}
void FileLightsLoader::close()
{
    in.close();
    opened = false;
}
std::shared_ptr<Light> read_ambient(Json::Value &root)
{
    std::shared_ptr<Light> light = std::shared_ptr<Light>(new AmbientLight(root["intensity"].asDouble()));
    return light;
}
std::shared_ptr<Light> read_point(Json::Value &root)
{
    Point p(root["point"]["x"].asDouble(),
            root["point"]["y"].asDouble(),
            root["point"]["z"].asDouble());
    std::shared_ptr<Light> light = std::shared_ptr<Light>(new PointLight(p, root["intensity"].asDouble()));
    return light;
}
std::shared_ptr<Light> read_directional(Json::Value &root)
{
    Point dir(root["direction"]["x"].asDouble(),
             root["direction"]["y"].asDouble(),
             root["direction"]["z"].asDouble());
    std::shared_ptr<Light> light = std::shared_ptr<Light>(new DirectionalLight(dir, root["intensity"].asDouble()));
    return light;
}
std::map<std::string, std::shared_ptr<Light> (*)(Json::Value &)> lightsReaders = {{"ambient", read_ambient},
                                                                                    {"point", read_point},
                                                                                    {"directional", read_directional}};

std::vector<std::shared_ptr<Light>> FileLightsLoader::load()
{
    std::vector<std::shared_ptr<Light>> lights;
    if (!opened)
        return lights;
    Json::CharReaderBuilder builder;
    JSONCPP_STRING errs;
    parseFromStream(builder, in, &root, &errs);
    for (int i = 0; i < root["lights"].size(); i++) {
        lights.push_back(lightsReaders[root["lights"][i]["type"].asString()](root["lights"][i]));
    }
    return lights;
}