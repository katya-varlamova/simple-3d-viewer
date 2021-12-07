//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_CAMERA_H
#define VIEW_CPP_CAMERA_H


#include "../Point.h"
#include "../../Containers/matrix/matrix/matrix.h"
class Camera {
public:
    Camera() = default;
    Camera(Point &position);
    Point getPosition();
    void setPosition(Point &position);
    Matrix<double> getDirection();
    void setDirection(Matrix<double> &direction);

    void move(Point mc);
    void rotate(Point rc);
private:
    Point position;
    Matrix<double> direction;
};


#endif //VIEW_CPP_CAMERA_H
