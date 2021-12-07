#include "View.h"
#include "ui_View.h"
#include <iostream>
#include "qdebug.h"
View::View(const char * configpath, QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::View)
{
    ui->setupUi(this);

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

    updateImage = true;
}
View::~View()
{
    delete ui;
}
void View::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if (updateImage)
    {
        std::shared_ptr<Drawer> drawer = std::shared_ptr<Drawer> (new QtDrawer(img, cw, ch));
        DrawCommand dc(da, drawer);
        facade->executeCommand(dc);
        updateImage = false;
    }
    painter.drawImage(QPoint(posx, posy), *img);
}
void View::print_error(QString message)
{
    ui->error_text->setTextColor(Qt::red);
    ui->error_text->setText(message);
}
void View::readFields(std::string &name, double &x, double &y, double &z)
{
    bool ok;
    name = ui->name_text->text().toStdString();

    x = ui->x_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("x is incorrect");
        return;
    }
    y = ui->y_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("y is incorrect");
        return;
    }
    z = ui->z_text->text().toDouble(&ok);
    if (!ok)
    {
        print_error("z is incorrect");
        return;
    }
}

void View::on_move_obj_but_clicked()
{
    double x, y, z;
    std::string name;
    readFields(name, x, y, z);
    Point p(x, y, z);
    MoveCommand mc(p, name);
    facade->executeCommand(mc);
    updateImage = true;
    repaint();
}

void View::on_scale_obj_but_clicked()
{
    double x, y, z;
    std::string name;
    readFields(name, x, y, z);
    Point p(x, y, z);
    ScaleCommand sc(p, name);
    facade->executeCommand(sc);

    updateImage = true;
    repaint();
}
void View::on_rotate_obj_but_clicked()
{

    double x, y, z;
    std::string name;
    readFields(name, x, y, z);
    Point p(x, y, z);
    RotateCommand rc(p, name);
    facade->executeCommand(rc);

    updateImage = true;
    repaint();
}

