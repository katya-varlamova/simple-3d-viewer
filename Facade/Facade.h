//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_FACADE_H
#define VIEW_CPP_FACADE_H

#include "../Commands/Command.h"
#include "../Scene/Scene.h"
class Facade
{
public:
    Facade();
    void executeCommand(Command &command);

protected:
    std::shared_ptr<Scene> scene;
};


#endif //VIEW_CPP_FACADE_H
