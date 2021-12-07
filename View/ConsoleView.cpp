//
// Created by Екатерина on 29.11.2021.
//

#include "ConsoleView.h"
ConsoleView::ConsoleView(const char *configpath)
{
    shared_ptr<ConfigLoader> fconfigl(new FileConfigLoader(configpath));
    fconfigl->open();
    std::shared_ptr<Configuration> configuration = fconfigl->load();
    fconfigl->close();


    da = std::shared_ptr<DrawerAlgo> (new RayTracer(1, 1, configuration->getDepth()));
    img = std::shared_ptr<QImage>(new QImage(cw + 1, ch + 1, QImage::Format_RGB32));
    facade = std::shared_ptr<Facade>(new Facade);

    shared_ptr<ObjectsLoader> fol(new FileObjectsLoader(configuration->getDataFileName()));
    shared_ptr<LightsLoader> fll(new FileLightsLoader(configuration->getLightsFileName()));
    shared_ptr<CameraLoader> fcl(new FileCameraLoader(configuration->getCameraFileName()));
    shared_ptr<SceneLoader> sl = std::shared_ptr<SceneLoader>(new SceneLoader(fol, fcl, fll));

    LoadCommand lc(sl);
    facade->executeCommand(lc);
}
void ConsoleView::saveImage()
{
    std::shared_ptr<Drawer> drawer = std::shared_ptr<Drawer> (new QtDrawer(img, cw, ch));
    DrawCommand dc(da, drawer);
    facade->executeCommand(dc);
    std::string path = QDir::currentPath().toStdString() + "/img.png";
    img->save(path.c_str());
}