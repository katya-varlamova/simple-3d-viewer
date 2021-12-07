//
// Created by Екатерина on 29.11.2021.
//

#ifndef VIEW_CPP_CONFIGURATION_H
#define VIEW_CPP_CONFIGURATION_H


#include <string>

class Configuration {
public:
    Configuration(std::string dataFileName,
                  std::string cameraFileName,
                  std::string lightsFileName,
                  int depth);
    std::string getDataFileName();
    std::string getCameraFileName();
    std::string getLightsFileName();
    int getDepth();
private:
    std::string dataFileName, cameraFileName, lightsFileName;
    int depth;
};


#endif //VIEW_CPP_CONFIGURATION_H
