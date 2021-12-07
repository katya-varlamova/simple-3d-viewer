#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <memory>
#include <QDir>
#include "ui_View.h"
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
#include <QPaintEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
Q_OBJECT

public:
    View(const char * configpath, QWidget *parent = nullptr);
    ~View();
    void paintEvent(QPaintEvent *event);
private slots:

    void on_move_obj_but_clicked();

    void on_scale_obj_but_clicked();

    void on_rotate_obj_but_clicked();

private:
    void readFields(std::string &name, double &x, double &y, double &z);
    void print_error(QString message);
    Ui::View *ui;
    std::shared_ptr<Facade> facade;
    std::shared_ptr<DrawerAlgo> da;
    std::shared_ptr<QImage> img;
    bool updateImage;
    int posx = 0, posy = 0, cw = 550, ch = 550;
};
#endif // VIEW_H
