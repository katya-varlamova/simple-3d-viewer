//
// Created by Екатерина on 29.10.2021.
//

#include "MoveCommand.h"
MoveCommand::MoveCommand(Point mc, std::string name)
{
    this->mc = mc;
    this->name = name;
}
void MoveCommand::execute(std::shared_ptr<Scene> &scene)
{
    for (auto &p : *scene)
    {
        if (p->getName() == name)
            p->move(mc);
    }
}