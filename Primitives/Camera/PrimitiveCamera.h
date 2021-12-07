//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_PRIMITIVECAMERA_H
#define VIEW_CPP_PRIMITIVECAMERA_H

#include "../Primitive.h"
#include "Camera.h"
#include <memory>
class PrimitiveCamera : public Primitive {
public:
    PrimitiveCamera(std::shared_ptr<Camera> &cam) :cam(cam){}
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;
    std::string getName() override;
protected:
    std::shared_ptr<Camera> cam;
};


#endif //VIEW_CPP_PRIMITIVECAMERA_H
