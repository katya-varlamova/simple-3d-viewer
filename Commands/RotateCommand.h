//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_ROTATECOMMAND_H
#define VIEW_CPP_ROTATECOMMAND_H


#include "Command.h"
#include "../Primitives/Point.h"
class RotateCommand : public Command{
public:
    RotateCommand(Point rc, std::string name);
    void execute(std::shared_ptr<Scene> &scene) override;

protected:
    std::string name;
    Point rc;
};


#endif //VIEW_CPP_ROTATECOMMAND_H
