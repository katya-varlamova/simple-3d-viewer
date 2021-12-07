//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_CAMERALOADER_H
#define VIEW_CPP_CAMERALOADER_H
#include <vector>
#include "../Primitives/Camera/Camera.h"
class CameraLoader {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual std::shared_ptr<Camera> load() = 0;
};


#endif //VIEW_CPP_CAMERALOADER_H
