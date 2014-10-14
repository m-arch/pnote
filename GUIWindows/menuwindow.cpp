#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include "notewindow.h"
#include "userswindow.h"
#include "../initialize.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    loadFirstUser();
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
    NoteWindow *nw = new NoteWindow(this);
    nw->show();
}

void MenuWindow::on_showUsersButton_clicked()
{
    this->hide();
    UsersWindow *uw = new UsersWindow(this);
    uw->show();
}

void MenuWindow::loadFirstUser()
{
    User user = initialize::Instance()->firstUser;
    this->setUserFields(user);
}

void MenuWindow::setUserFields(User user)
{
    ui->username->setText(user.firstName + " "+ user.lastName);
    ui->phone->setText(user.phone);
    ui->othercontact->setText(user.otherContact);
    ui->notes->setText(user.notes);
    ui->userId->setText(user.id);
    ui->nextId->setText(user.nextId);
    ui->previousId->setText(user.previousId);
}

void MenuWindow::on_nextUser_clicked()
{
    User user;
    user = user.getUserbyId(ui->nextId->text());
    if (user.id != "")
    {
        setUserFields(user);
    }
}



void MenuWindow::on_previousUser_clicked()
{
    User user;
    user = user.getUserbyId(ui->previousId->text());
    if (user.id != "")
    {
        setUserFields(user);
    }
}
