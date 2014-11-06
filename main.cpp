#include <QApplication>
#include "GUIWindows/menuwindow.h"
#include "initialize.h"
#include "logic/dbsetup.h"
#include "logic/generatepdf.h"

int main(int argc, char *argv[])
{
    //dbSetup();
    QString file;
    QApplication a(argc, argv);
    initialize::Instance();
    MenuWindow *mw = new MenuWindow();
    mw->show();
    return a.exec();
}

