//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_FILECAMERALOADER_H
#define VIEW_CPP_FILECAMERALOADER_H

#include <fstream>
#include <value.h>
#include "../CameraLoader.h"
class FileCameraLoader : public CameraLoader{
public:
    explicit FileCameraLoader(std::string filename);
    void close() override;
    std::shared_ptr<Camera> load() override;
    void open() override;
private:
    std::string filename;
    std::ifstream in;
    bool opened = false;
    Json::Value root;
};


#endif //VIEW_CPP_FILECAMERALOADER_H
