#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include "notewindow.h"
#include "userswindow.h"
#include "../initialize.h"
#include "../logic/utilities.h"
#include <QImage>

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
    nw->setUserIdLabel(ui->userId->text());
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
    while ( QWidget* w = ui->carsSection->findChild<QWidget*>() )
            delete w;

    ui->username->setText(user.firstName.replace("  ","") + "   "+ user.lastName.replace("  ",""));
    ui->phone->setText(user.phone);
    ui->othercontact->setText(user.otherContact);
    ui->notes->setText(user.notes);
    ui->userId->setText(user.id);
    ui->nextId->setText(user.nextId);
    ui->previousId->setText(user.previousId);
    fillCarsWidget(ui->carsSection, user.userCarsHash);
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

void fillCarsWidget(QWidget *carsWidget,unordered_map<QString, userCar> userCarsHash)
{
    int wwidth = carsWidget->width();
    int nbrpline = (int)wwidth/191;
    unordered_map<QString, userCar>::iterator ucItr;
    int counter = 0;
    for ( ucItr = userCarsHash.begin(); ucItr != userCarsHash.end(); ucItr++)
    {
        userCar tmpCar = (*ucItr).second;
        QPixmap pixmap = getPixmapfromURL(tmpCar.photo);
        drawCar(carsWidget, pixmap, tmpCar.brand, tmpCar.model, tmpCar.motor, tmpCar.year, (191* (counter%nbrpline))+30, (150 * (int)(counter/nbrpline)) + 30);
        counter++;
    }
}


void drawCar(QWidget *parentWidget, QPixmap pix, QString brand, QString model, QString motor, int year,int px,int py)
{
    QWidget *wid = new QWidget(parentWidget);
    wid->setGeometry(px, py, 131, 131);
    QLabel *img = new QLabel(wid);
    img->setGeometry(0, 0, 131, 61);
    img->setPixmap(pix);
    QLabel *modelbrand = new QLabel(wid);
    modelbrand->setGeometry(0, 72, 131, 22);
    QLabel *motoryear = new QLabel(wid);
    motoryear->setGeometry(0, 94, 131, 22);
    brand.replace("  ","");
    model.replace("  ","");
    motor.replace("  ","");
    modelbrand->setText(brand +"  "+ model);
    motoryear->setText(motor +"  "+ QString::number(year));
    wid->show();
}
