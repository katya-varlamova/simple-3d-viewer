//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_OBJECTSLOADER_H
#define VIEW_CPP_OBJECTSLOADER_H
#include <vector>
#include "../Primitives/Surfaces/Object.h"
class ObjectsLoader {
public:
    virtual void open() = 0;
    virtual std::vector<std::shared_ptr<Object>> load() = 0;
    virtual void close() = 0;
};


#endif //VIEW_CPP_OBJECTSLOADER_H
