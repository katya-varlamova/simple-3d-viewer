//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_PRIMITIVE_H
#define VIEW_CPP_PRIMITIVE_H

#include "Point.h"
#include <string>
class Primitive {
public:
    virtual void move(Point mc) = 0;
    virtual void scale(Point sc) = 0;
    virtual void rotate(Point rc) = 0;
    virtual std::string getName() = 0;
};


#endif //VIEW_CPP_PRIMITIVE_H
