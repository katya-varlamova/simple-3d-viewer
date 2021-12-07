//
// Created by Екатерина on 29.10.2021.
//

#include "LoadCommand.h"
void LoadCommand::execute(std::shared_ptr<Scene> &scene)
{
    sl->open();
    scene = sl->load();
    sl->close();
}