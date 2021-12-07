//
// Created by Екатерина on 29.10.2021.
//

#include "Facade.h"
Facade::Facade()
{
}
void Facade::executeCommand(Command &command)
{
    command.execute(scene);
}