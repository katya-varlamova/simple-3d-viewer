//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_LIGHTSLOADER_H
#define VIEW_CPP_LIGHTSLOADER_H

#include <vector>
#include "../Primitives/Light/Light.h"

class LightsLoader {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual std::vector<std::shared_ptr<Light>> load() = 0;
};


#endif //VIEW_CPP_LIGHTSLOADER_H
