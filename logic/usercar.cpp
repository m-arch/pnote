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

std::tr1::unordered_map<int, userCar> userCar::makeUserCarsHash(QString userId)
{
    std::tr1::unordered_map<int, userCar> tmpHash;
    QSqlQuery query;
    QString VIN, plateNumber, color, brand, model, motor;
    int id, year;
    query.exec("SELECT ID, VIN, Plate_Number, CAR_COLOR, CAR_BRAND, CAR_BODY_MODEL, CAR_MOTOR, CAR_YEAR FROM pnote.user_car WHERE user_ID = '" + userId +"' ;" );
    while (query.next()){
        id = query.value(0).toInt();
        VIN = query.value(1).toString().trimmed();
        plateNumber = query.value(2).toString().trimmed();
        color = query.value(3).toString().trimmed();
        brand = query.value(4).toString().trimmed();
        model = query.value(5).toString().trimmed();
        motor = query.value(6).toString().trimmed();
        year = query.value(7).toInt();

        this->setCar(id, VIN, plateNumber, userId, color, brand, model, motor, year);
        tmpHash.insert(std::make_pair(id, *this));
    }
    return tmpHash;
}

void userCar::setCar(int Id, QString VIN, QString plateNumber, QString userId, QString color, QString brand, QString model, QString motor, int year)
{
    this->id = Id;
    this->VIN = VIN;
    this->plateNumber = plateNumber;
    this->userId = userId;
    this->color = color;
    this->brand = brand;
    this->model = model;
    this->motor = motor;
    this->year = year;
}

void userCar::setCar(QString VIN, QString plateNumber, QString userId, QString color, QString brand, QString model, QString motor, int year)
{
    this->VIN = VIN;
    this->plateNumber = plateNumber;
    this->userId = userId;
    this->color = color;
    this->brand = brand;
    this->model = model;
    this->motor = motor;
    this->year = year;
}

void userCar::insertUserCar()
{
    QString queryStr;
    QSqlQuery query ;
    unordered_map<QString, User> usersHash = initialize::Instance()->getUsersHash();

    queryStr = "INSERT INTO pnote.user_car (VIN, Plate_Number, user_ID, CAR_COLOR, CAR_BRAND, CAR_BODY_MODEL, CAR_MOTOR, CAR_YEAR) VALUES ('"
                    + this->VIN + "', '"
                    + this->plateNumber + "', '"
                    + this->userId + "', '"
                    + this->color + "', '"
                    + this->brand + "', '"
                    + this->model + "', '"
                    + this->motor + "', '"
                    + QString::number(this->year) +"') returning ID;";
    qDebug() << queryStr;
    query.exec(queryStr);
    while (query.next()){
        this->id = query.value(0).toInt();
    }
    User hashUser = usersHash[this->userId];
    hashUser.userCarsHash.insert(std::make_pair(this->id, *this));
    initialize::Instance()->updateHashEntry(hashUser);

}

