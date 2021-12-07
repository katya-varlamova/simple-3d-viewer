//
// Created by Екатерина on 29.11.2021.
//

#ifndef VIEW_CPP_CONFIGLOADER_H
#define VIEW_CPP_CONFIGLOADER_H
#include <memory>
#include "Configuration.h"
class ConfigLoader {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual std::shared_ptr<Configuration> load() = 0;
};


#endif //VIEW_CPP_CONFIGLOADER_H
