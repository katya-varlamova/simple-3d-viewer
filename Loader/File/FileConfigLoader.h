//
// Created by Екатерина on 29.11.2021.
//

#ifndef VIEW_CPP_FILECONFIGLOADER_H
#define VIEW_CPP_FILECONFIGLOADER_H

#include "../ConfigLoader.h"
#include "json.h"
#include <fstream>
#include <iostream>
#include <memory>
class FileConfigLoader : public ConfigLoader{
public:
    explicit FileConfigLoader(const char * filename);
    void open() override;
    void close() override;
    std::shared_ptr<Configuration> load() override;

protected:
    std::string filename;
    std::ifstream in;
    bool opened = false;
    Json::Value root;
};


#endif //VIEW_CPP_FILECONFIGLOADER_H
