#include <QApplication>
#include "menuwindow.h"


int main(int argc, char *argv[])
{
    QString file;
    QApplication a(argc, argv);
    MenuWindow *mw = new MenuWindow();
    mw->show();
    return a.exec();
}

