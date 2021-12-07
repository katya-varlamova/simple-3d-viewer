//
// Created by Екатерина on 29.11.2021.
//

#include "FileConfigLoader.h"
FileConfigLoader::FileConfigLoader(const char *filename)
{
    this->filename = filename;
}
void FileConfigLoader::open()
{
    in.open(filename);
    opened = true;
}
void FileConfigLoader::close()
{
    in.close();
    opened = false;
}
std::shared_ptr<Configuration> FileConfigLoader::load()
{
    std::shared_ptr<Configuration> configuration;
    if (!opened)
        return configuration;
    Json::CharReaderBuilder builder;
    JSONCPP_STRING errs;
    parseFromStream(builder, in, &root, &errs);
    int depth = root["depth"].asInt();
    std::string dfn = root["dfn"].asString();
    std::string cfn = root["cfn"].asString();
    std::string lfn = root["lfn"].asString();
    configuration = std::shared_ptr<Configuration>(new Configuration(dfn, cfn, lfn, depth));
    return configuration;
}