#include <QApplication>
#include "menuwindow.h"
#include "initialize.h"

int main(int argc, char *argv[])
{
    QString file;
    QApplication a(argc, argv);
    initialize::Instance()->initializeUsersHash();
    MenuWindow *mw = new MenuWindow();
    mw->show();
    return a.exec();
}

