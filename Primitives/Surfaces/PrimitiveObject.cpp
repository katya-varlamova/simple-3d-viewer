//
// Created by Екатерина on 29.10.2021.
//

#include "PrimitiveObject.h"
void PrimitiveObject::move(Point mc)
{
    object->setCenter(object->getCenter() - mc);
    object->move(mc);
}
void PrimitiveObject::scale(Point sc)
{
    object->move(object->getCenter());
    object->scale(sc);
    object->move(-object->getCenter());
}
void PrimitiveObject::rotate(Point rc)
{
    object->move(object->getCenter());
    object->rotate(rc);
    object->move(-object->getCenter());
}
std::string PrimitiveObject::getName() {
    return object->getName();
}