//
// Created by Екатерина on 25.10.2021.
//

#include <json.h>
#include "FileCameraLoader.h"
FileCameraLoader::FileCameraLoader(std::string filename)
{
    this->filename = filename;
}
void FileCameraLoader::open()
{
    in.open(filename);
    opened = true;
}
void FileCameraLoader::close()
{
    in.close();
    opened = false;
}
static double to_rad(double ang)
{
    double ret = ang * (M_PI / 180.0);
    return ret;
}
std::shared_ptr<Camera> FileCameraLoader::load()
{
    std::shared_ptr<Camera> cam;
    if (!opened)
        return cam;
    Json::CharReaderBuilder builder;
    JSONCPP_STRING errs;
    parseFromStream(builder, in, &root, &errs);
    Point pos = Point(root["camera"]["position"]["x"].asDouble(),
                    root["camera"]["position"]["y"].asDouble(),
                    root["camera"]["position"]["z"].asDouble());
    Point rot = Point(to_rad(root["camera"]["rotation"]["x"].asDouble()),
                      to_rad(root["camera"]["rotation"]["y"].asDouble()),
                      to_rad(root["camera"]["rotation"]["z"].asDouble()));
    cam = std::shared_ptr<Camera>(new Camera(pos));
    cam->rotate(rot);
    return cam;
}