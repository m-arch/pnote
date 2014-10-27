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

std::tr1::unordered_map<QString, userCar> userCar::makeUserCarsHash(QString userId)
{
    std::tr1::unordered_map<QString, userCar> tmpHash;
    QSqlQuery query;
    QString id, photo, brand, model, motor;
    int year;
    query.exec("SELECT ID, CAR_PHOTO, CAR_BRAND, CAR_BODY_MODEL, CAR_MOTOR, CAR_YEAR FROM pnote.user_car WHERE user_ID = '" + userId +"' ;" );
    while (query.next()){
        id = query.value(0).toString();
        photo = query.value(1).toString();
        brand = query.value(2).toString();
        model = query.value(3).toString();
        motor = query.value(4).toString();
        year = query.value(5).toInt();
        this->setCar(id, userId, photo, brand, model, motor, year);
        tmpHash.insert(std::make_pair(id, *this));
    }
    return tmpHash;
}


void userCar::setCar(QString Id, QString userId, QString photo, QString brand, QString model, QString motor, int year)
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
    unordered_map<QString, User> usersHash = initialize::Instance()->getUsersHash();

    queryStr = "INSERT INTO pnote.user_car (ID, user_ID, CAR_PHOTO, CAR_BRAND, CAR_BODY_MODEL, CAR_MOTOR, CAR_YEAR) VALUES ('"
                    + this->id + "', '"
                    + this->userId + "', '"
                    + this->photo + "', '"
                    + this->brand + "', '"
                    + this->model + "', '"
                    + this->motor + "', '"
                    + QString::number(this->year) +"');";
    qDebug() << queryStr;
    query.exec(queryStr);
    User hashUser = usersHash[this->userId];
    hashUser.userCarsHash.insert(std::make_pair(this->id, *this));
    initialize::Instance()->setUsersHash(usersHash);

}
