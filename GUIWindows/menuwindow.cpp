#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include "usercarswindow.h"
#include "userswindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_addUserButton_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow(this);
    w->show();
}

void MenuWindow::on_addNoteButton_clicked()
{
    this->hide();
    UserCarsWindow *nw = new UserCarsWindow(this);
    nw->show();
}

void MenuWindow::on_showUsersButton_clicked()
{
    this->hide();
    UsersWindow *uw = new UsersWindow(this);
    uw->show();
}
