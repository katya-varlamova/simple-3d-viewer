//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_PRIMITIVEOBJECT_H
#define VIEW_CPP_PRIMITIVEOBJECT_H

#include "../Primitive.h"
#include "Surface.h"
#include <memory>
class PrimitiveObject : public Primitive {
public:
    PrimitiveObject(std::shared_ptr<Object> &object) : object(object){}
    void move(Point mc) override;
    void scale(Point sc) override;
    void rotate(Point rc) override;
    std::string getName() override;
protected:
    std::shared_ptr<Object> object;
};


#endif //VIEW_CPP_PRIMITIVEOBJECT_H
