#include "usercar.h"
#include <QtSql>
#include <QCoreApplication>

userCar::userCar()
{
}

std::tr1::unordered_map<string, userCar> userCar::makeUserCarsHash(string userId)
{
    std::tr1::unordered_map<string, userCar> tmpHash;
    QSqlQuery query;
    userCar tmpCar;
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
        tmpCar.setCar(id, userId, photo, brand, model, motor, year);
        tmpHash.insert(std::make_pair(id, tmpCar));
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
