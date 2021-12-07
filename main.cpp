#include <QApplication>
#include <QCoreApplication>
#include "View/View.h"
#include "View/ConsoleView.h"

QCoreApplication *createApplication(int &argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (!qstrcmp(argv[i], "-no-gui")) {
            return new QCoreApplication(argc, argv);
        }
    }
    return new QApplication(argc, argv);
}

int main(int argc, char *argv[]) {
    if (argc < 2)
        return 1;
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    if (!qobject_cast<QApplication *>(app.data())) {
        ConsoleView cw(argv[1]);
        cw.saveImage();
        return 0;
    }
    View w(argv[1]);
    w.show();
    return app->exec();
}