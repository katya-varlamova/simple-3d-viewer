//
// Created by Екатерина on 29.10.2021.
//

#include "RotateCommand.h"
RotateCommand::RotateCommand(Point mc, std::string name)
{
    this->rc = mc;
    this->name = name;
}
void RotateCommand::execute(std::shared_ptr<Scene> &scene)
{
    for (auto &p : *scene)
    {
        if (p->getName() == name)
            p->rotate(rc);
    }
}