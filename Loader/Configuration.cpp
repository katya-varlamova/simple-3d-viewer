//
// Created by Екатерина on 29.11.2021.
//

#include "Configuration.h"
Configuration::Configuration(std::string dataFileName,
                             std::string cameraFileName,
                             std::string lightsFileName,
                             int depth)
{
    this->dataFileName = dataFileName;
    this->cameraFileName = cameraFileName;
    this->lightsFileName = lightsFileName;
    this->depth = depth;
}
std::string Configuration::getCameraFileName()
{
    return cameraFileName;
}
std::string Configuration::getDataFileName()
{
    return dataFileName;
}
int Configuration::getDepth()
{
    return depth;
}
std::string Configuration::getLightsFileName()
{
    return lightsFileName;
}