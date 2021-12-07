//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_MOVEOBJECTCOMMAND_H
#define VIEW_CPP_MOVEOBJECTCOMMAND_H

#include "Command.h"
#include "../Primitives/Point.h"
class MoveCommand : public Command{
public:
    MoveCommand(Point mc, std::string name);
    void execute(std::shared_ptr<Scene> &scene) override;

protected:
    std::string name;
    Point mc;
};


#endif //VIEW_CPP_MOVEOBJECTCOMMAND_H
