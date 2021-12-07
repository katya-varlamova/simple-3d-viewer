//
// Created by Екатерина on 05.10.2021.
//

#ifndef VIEWER_FILELOADER_H
#define VIEWER_FILELOADER_H

#include "json.h"
#include <fstream>
#include <iostream>

#include "../../Primitives/Surfaces/Object.h"
#include "../../Primitives/Surfaces/Surface.h"
#include "../../Primitives/Surfaces/CompositeSurface.h"
#include "../../Primitives/Surfaces/Torus.h"
#include "../../Primitives/Surfaces/CollectionSurface.h"
#include "../ObjectsLoader.h"
#include "../../Drawer/DrawerColor.h"
using namespace std;

class FileObjectsLoader : public ObjectsLoader{
public:
    explicit FileObjectsLoader(std::string filename);
    void open() override;
    std::vector<std::shared_ptr<Object>> load() override;
    void close() override;
private:
    std::string filename;
    std::ifstream in;
    bool opened = false;
    Json::Value root;
};


#endif //VIEWER_FILELOADER_H
