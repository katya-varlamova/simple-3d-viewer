//
// Created by Екатерина on 25.10.2021.
//

#ifndef VIEW_CPP_COMMAND_H
#define VIEW_CPP_COMMAND_H

#include "../Scene/Scene.h"
class Command
{
public:
    Command() = default;
    virtual void execute(std::shared_ptr<Scene> &scene) = 0;

};

#endif //VIEW_CPP_COMMAND_H
