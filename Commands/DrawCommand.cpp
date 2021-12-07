//
// Created by Екатерина on 31.10.2021.
//

#include "DrawCommand.h"
void DrawCommand::execute(std::shared_ptr<Scene> &scene)
{
    scene->setDrawerAlgo(algo);
    scene->draw(drawer);

}