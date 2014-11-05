#include "dbsearch.h"
#include <QCoreApplication>
#include <QtSql>

void getUserandCarFromVIN (QString VIN, User *user, userCar *car){

    QString userId;
    int carId;
    QSqlQuery query;
    QString queryStr;
    queryStr = "SELECT pnote.user.id, pnote.user_car.id From pnote.user inner join pnote.user_car ON (pnote.user.ID = pnote.user_car.user_id) WHERE pnote.user_car.VIN = '" + VIN + "';";
    qDebug() << queryStr;
    query.exec(queryStr);
    while (query.next()){
        userId = query.value(0).toString();
        carId = query.value(1).toInt();
    }
    *user = getUserbyId(userId);
    *car = user->userCarsHash[QString::number(carId)];
}
