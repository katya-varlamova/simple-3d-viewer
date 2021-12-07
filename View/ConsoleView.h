//
// Created by Екатерина on 29.11.2021.
//

#ifndef VIEWER_CONSOLEVIEW_H
#define VIEWER_CONSOLEVIEW_H
#include <memory>
#include <QDir>
#include "../Loader/File/FileConfigLoader.h"
#include "../Containers/matrix/matrix/matrix.h"
#include "../Scene/RayTracer/RayTracer.h"
#include "../Drawer/QtDrawer.h"
#include "../Facade/Facade.h"
#include "../Commands/MoveCommand.h"
#include "../Commands/RotateCommand.h"
#include "../Commands/ScaleCommand.h"
#include "../Commands/DrawCommand.h"
#include "../Commands/LoadCommand.h"
#include "../Loader/File/FileObjectsLoader.h"
#include "../Loader/File/FileLightsLoader.h"
#include "../Loader/File/FileCameraLoader.h"

class ConsoleView {
public:
    explicit ConsoleView(const char * configpath);
    void saveImage();

private:
    std::shared_ptr<Facade> facade;
    std::shared_ptr<DrawerAlgo> da;
    std::shared_ptr<QImage> img;
    int cw = 300, ch = 300;
};


#endif //VIEWER_CONSOLEVIEW_H
