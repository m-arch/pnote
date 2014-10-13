#ifndef USER_H
#define USER_H
#include <QString>
#include "usercar.h"
#include <tr1/unordered_map>
#include "../extensions.h"

using namespace std;

class User
{
private:


public:
    User();
    User getUserbyId(QString);
    void setUser(QString, QString, QString, QString, QString, std::tr1::unordered_map<QString, userCar>);
    void setUser(QString, QString, QString, QString, QString, QString, std::tr1::unordered_map<QString, userCar>);
    void getUsersHash();
    void deleteUser(QString);
    QString id, firstName, lastName, phone, otherContact, notes;
    std::tr1::unordered_map<QString, userCar> userCarsHash;
    //void updateUser....
};

#endif // USER_H
