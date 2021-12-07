//
// Created by Екатерина on 29.10.2021.
//

#include "ScaleCommand.h"
ScaleCommand::ScaleCommand(Point sc, std::string name)
{
    this->sc = sc;
    this->name = name;
}
void ScaleCommand::execute(std::shared_ptr<Scene> &scene)
{
    for (auto &p : *scene)
    {
        if (p->getName() == name)
            p->scale(sc);
    }
}