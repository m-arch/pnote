#include "usercarswindow.h"
#include "ui_usercarswindow.h"
#include <QImage>
#include "../logic/utilities.h"
#include <tr1/unordered_map>
#include "../initialize.h"
using namespace std::tr1;

UserCarsWindow::UserCarsWindow(QWidget *parent, User *user) :
    QMainWindow(parent),
    ui(new Ui::UserCarsWindow)
{
    ui->setupUi(this);
    addUserCars(user);
}

UserCarsWindow::~UserCarsWindow()
{
    delete ui;
}

void UserCarsWindow::addUserCars(User *user)
{
    unordered_map<QString, User> usersHash = initialize::Instance()->getUsersHash();
    User hashUser = usersHash[user->id];
    unordered_map<QString, userCar> userCarsHash = hashUser.userCarsHash;
    unordered_map<QString, userCar>::iterator ucItr;
    for ( ucItr = userCarsHash.begin(); ucItr != userCarsHash.end(); ucItr++)
    {
        userCar tmpCar = (*ucItr).second;
        QPixmap pixmap = getPixmapfromURL(tmpCar.photo);
        generateCarwidget(pixmap, tmpCar.brand, tmpCar.model, tmpCar.motor, tmpCar.year, 70, 90);

    }
    ui->username->setText(user->firstName + " "+ user->lastName);
    ui->phone->setText(user->phone);
    ui->othercontact->setText(user->otherContact);
}

void UserCarsWindow::generateCarwidget(QPixmap pix, QString brand, QString model, QString motor, int year,int px,int py)
{
    QWidget *wid = new QWidget(this);
    wid->setGeometry(px, py, 121, 121);
    QLabel *img = new QLabel(wid);
    img->setGeometry(0, 0, 121, 61);
    img->setPixmap(pix);
    QLabel *modelbrand = new QLabel(wid);
    modelbrand->setGeometry(0, 62, 119, 22);
    QLabel *motoryear = new QLabel(wid);
    motoryear->setGeometry(0, 85, 119, 22);
    modelbrand->setText(brand +"  "+ model);
    motoryear->setText(motor +"  "+ year);
    wid->show();
}
