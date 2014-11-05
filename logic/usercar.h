#ifndef USERCAR_H
#define USERCAR_H
#include <QString>
#include <tr1/unordered_map>
#include "../extensions.h"

using namespace std;

class userCar
{
private:


public:
    userCar();
    void setCar(QString, QString, QString, QString, QString, QString, QString, int);
    void setCar(int, QString, QString, QString, QString, QString, QString, QString, int);
    void insertUserCar();
    QString brand, model, motor, color, plateNumber, VIN;
    int year;
    std::tr1::unordered_map<QString, userCar> makeUserCarsHash(QString);
    QString userId;
    int id;

};

#endif // USERCAR_H
