//
// Created by Екатерина on 31.10.2021.
//

#ifndef VIEW_CPP_DRAWCOMMAND_H
#define VIEW_CPP_DRAWCOMMAND_H

#include "Command.h"
#include "../Scene/DrawerAlgo.h"
#include "../Drawer/Drawer.h"
class DrawCommand : public Command{
public:
    DrawCommand(std::shared_ptr<DrawerAlgo> &algo, std::shared_ptr<Drawer> &drawer)
    {
        this->algo = algo;
        this->drawer = drawer;
    }
    void execute(std::shared_ptr<Scene> &scene) override;

private:
    std::shared_ptr<DrawerAlgo> algo;
    std::shared_ptr<Drawer> drawer;
};


#endif //VIEW_CPP_DRAWCOMMAND_H
