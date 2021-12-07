//
// Created by Екатерина on 29.10.2021.
//

#ifndef VIEW_CPP_SCALECOMMAND_H
#define VIEW_CPP_SCALECOMMAND_H


#include "Command.h"
#include "../Primitives/Point.h"
class ScaleCommand : public Command{
public:
    ScaleCommand(Point sc, std::string name);
    void execute(std::shared_ptr<Scene> &scene) override;

protected:
    std::string name;
    Point sc;
};



#endif //VIEW_CPP_SCALECOMMAND_H
