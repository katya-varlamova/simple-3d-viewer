//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_PRIMITIVELIGHT_H
#define VIEW_CPP_PRIMITIVELIGHT_H
#include "Light.h"
#include "../Primitive.h"
#include <memory>
class PrimitiveLight : public Primitive {
public:
    PrimitiveLight(std::shared_ptr<Light> &light) :light(light){}
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;
    std::string getName() override;
protected:
    std::shared_ptr<Light> light;
};


#endif //VIEW_CPP_PRIMITIVELIGHT_H
