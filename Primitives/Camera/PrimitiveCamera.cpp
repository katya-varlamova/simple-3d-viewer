//
// Created by Екатерина on 29.10.2021.
//

#include "PrimitiveCamera.h"
void PrimitiveCamera::move(Point mc)
{
    cam->move(mc);
}
void PrimitiveCamera::rotate(Point rc)
{
    cam->rotate(rc);
}
void PrimitiveCamera::scale(Point sc)
{
    //todo exception
}
std::string PrimitiveCamera::getName()
{
    return "camera";
}