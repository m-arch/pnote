#include "usercar.h"
#include "user.h"
#include <QtSql>
#include <QCoreApplication>
#include <tr1/unordered_map>
#include "../initialize.h"

using namespace std::tr1;

userCar::userCar()
{
}

std::tr1::unordered_map<string, userCar> userCar::makeUserCarsHash(string userId)
{
    std::tr1::unordered_map<string, userCar> tmpHash;
    QSqlQuery query;
    std::string id, photo, brand, model, motor;
    int year;
    query.exec("SELECT ID, CAR_PHOTO, CAR_BRAND, CAR_BODY_MODEL, CAR_MOTOR, CAR_YEAR FROM pnote.user_car WHERE user_ID = " + QString::fromStdString(userId) +";" );
    while (query.next()){
        id = query.value(0).toString().toStdString();
        photo = query.value(1).toString().toStdString();
        brand = query.value(2).toString().toStdString();
        model = query.value(3).toString().toStdString();
        motor = query.value(4).toString().toStdString();
        year = query.value(5).toInt();
        this->setCar(id, userId, photo, brand, model, motor, year);
        tmpHash.insert(std::make_pair(id, *this));
    }
    return tmpHash;
}


void userCar::setCar(string Id, string userId, string photo, string brand, string model, string motor, int year)
{
    this->id = Id;
    this->userId = userId;
    this->photo = photo;
    this->brand = brand;
    this->model = model;
    this->motor = motor;
    this->year = year;
}

void userCar::insertUserCar()
{
    QString queryStr;
    QSqlQuery query ;
    unordered_map<std::string, User> usersHash = initialize::Instance()->getUsersHash();

    queryStr = "INSERT INTO pnote.user_car (ID, user_ID, CAR_PHOTO, CAR_BRAND, CAR_BODY_MODEL, CAR_MOTOR, CAR_YEAR) VALUES ('"
                    + QString::fromStdString(this->id) + "', '"
                    + QString::fromStdString(this->userId) + "', '"
                    + QString::fromStdString(this->photo) + "', '"
                    + QString::fromStdString(this->brand) + "', '"
                    + QString::fromStdString(this->model) + "', '"
                    + QString::fromStdString(this->motor) + "', '"
                    + QString::number(this->year) +"');";
    qDebug() << queryStr;
    query.exec(queryStr);
    User hashUser = usersHash[this->userId];
    hashUser.userCarsHash.insert(std::make_pair(this->id, *this));

}
