#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "mainwindow.h"
#include "notewindow.h"
#include "userswindow.h"
#include "vinlookup.h"
#include "../initialize.h"
#include "../logic/utilities.h"
#include <QImage>
#include "cartab.h"

MenuWindow::MenuWindow(QWidget *parent, User *user) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    if(user != 0)
        loadUser(*user);
    else
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


void MenuWindow::loadFirstUser()
{
    User user = initialize::Instance()->firstUser;
    this->setUserFields(user);
}

void MenuWindow::loadUser(User user)
{
    this->setUserFields(user);
}

void MenuWindow::setUserFields(User user)
{
    while ( QTabWidget* w = ui->carsSection->findChild<QTabWidget*>() )
            delete w;

    ui->username->setText(user.firstName.replace("  ","") + "   "+ user.lastName.replace("  ",""));
    ui->phone->setText(user.phone);
    ui->othercontact->setText(user.otherContact);
    ui->notes->setText(user.notes);
    ui->userId->setText(user.id);
    ui->nextId->setText(user.nextId);
    ui->previousId->setText(user.previousId);
    setCarsFields (ui->carsSection, user.userCarsHash);
    //fillCarsWidget(ui->carsSection, user.userCarsHash);
}

void MenuWindow::on_nextUser_clicked()
{
    User user;
    user = getUserbyId(ui->nextId->text());
    if (user.id != "")
    {
        setUserFields(user);
    }
}



void MenuWindow::on_previousUser_clicked()
{
    User user;
    user = getUserbyId(ui->previousId->text());
    if (user.id != "")
    {
        setUserFields(user);
    }
}

void setCarsFields(QWidget *carsWidget, unordered_map<int, userCar> userCarsHash)
{
    unordered_map<int, userCar>::iterator ucItr;
    QTabWidget *twid = new QTabWidget(carsWidget);
    twid->setGeometry(0, 0, carsWidget->width(), carsWidget->height());
    for ( ucItr = userCarsHash.begin(); ucItr != userCarsHash.end(); ucItr++)
    {
        userCar tmpCar = (*ucItr).second;
        carTab *ct = new carTab(&tmpCar);
        twid->addTab(ct, tmpCar.brand);
    }
    twid->show();
}

void fillCarWidget(QWidget *widg, userCar car)
{

}

void fillCarsWidget(QWidget *carsWidget,unordered_map<int, userCar> userCarsHash)
{
    int wwidth = carsWidget->width();
    int nbrpline = (int)wwidth/191;
    unordered_map<int, userCar>::iterator ucItr;
    int counter = 0;
    for ( ucItr = userCarsHash.begin(); ucItr != userCarsHash.end(); ucItr++)
    {
        userCar tmpCar = (*ucItr).second;
        QPixmap pixmap = getPixmapfromURL(tmpCar.color);
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
    brand.trimmed();
    model.trimmed();
    motor.trimmed();
    modelbrand->setText(brand +"  "+ model);
    motoryear->setText(motor +"  "+ QString::number(year));
    wid->show();
}


void MenuWindow::on_printVinButton_clicked()
{
    vinlookup *vinw = new vinlookup(this);
    vinw->show();
}
