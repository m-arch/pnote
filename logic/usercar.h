#ifndef USERCAR_H
#define USERCAR_H
#include <QString>
#include <tr1/unordered_map>
#include "../extensions.h"

using namespace std;

class userCar
{
private:
    QString id, userId;

public:
    userCar();
    void setCar(QString, QString, QString, QString, QString, QString, int);
    void insertUserCar();
    QString brand, model, motor, photo;
    int year;
    std::tr1::unordered_map<QString, userCar> makeUserCarsHash(QString);

};

#endif // USERCAR_H
