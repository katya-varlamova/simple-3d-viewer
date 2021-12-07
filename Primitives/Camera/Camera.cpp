//
// Created by Екатерина on 25.10.2021.
//

#include "Camera.h"
Camera::Camera(Point &position)
{
    this->position = position;
    this->direction = Matrix<double>({{1, 0, 0},
                                      {0, 1, 0},
                                      {0, 0, 1}});
}
void Camera::move(Point mc)
{
    position += mc;
}
static double to_rad(double ang)
{
    return ang * (M_PI / 180.0);
}
void Camera::rotate(Point rc)
{
    rc = Point(to_rad(rc.getX()),
               to_rad(rc.getY()),
               to_rad(rc.getZ()));

    Matrix<double> rotationX = {{1, 0, 0},
                                {0, cos(rc.getX()), -sin(rc.getX())},
                                {0, sin(rc.getX()), cos(rc.getX())}};

    Matrix<double> rotationY = {{cos(rc.getY()), 0, -sin(rc.getY())},
                                {0, 1, 0},
                                {sin(rc.getY()), 0, cos(rc.getY())}};

    Matrix<double> rotationZ = {{cos(rc.getZ()), -sin(rc.getZ()), 0},
                                {sin(rc.getZ()), cos(rc.getZ()), 0},
                                {0, 0, 1}};
    this->direction *= rotationX * rotationY * rotationZ;
}
Point Camera::getPosition()
{
    return position;
}
Matrix<double> Camera::getDirection()
{
    return Matrix<double>(direction);
}
void Camera::setDirection(Matrix<double> &direction)
{
    this->direction = direction;
}
void Camera::setPosition(Point &position)
{
    this->position = position;
}