//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_LOADCOMMAND_H
#define VIEW_CPP_LOADCOMMAND_H
#include "../Loader/SceneLoader.h"
#include "Command.h"
class LoadCommand : public Command{
public:
    LoadCommand(std::shared_ptr<SceneLoader> &sl)
    {
        this->sl = sl;
    }
    void execute(std::shared_ptr<Scene> &scene) override;

private:
    std::shared_ptr<SceneLoader> sl;
};


#endif //VIEW_CPP_LOADCOMMAND_H
