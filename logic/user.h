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
    void setUser(QString, QString, QString, QString, QString, QString, QString, std::tr1::unordered_map<QString, userCar>);
    void setUser(QString, QString, QString, QString, QString, QString, QString);
    void getUsersHash();
    void insertUser();
    void deleteUser(QString);
    void updateUser(User*);
    QString id, firstName, lastName, phone, otherContact, notes, nextId, previousId;
    std::tr1::unordered_map<QString, userCar> userCarsHash;
    //void updateUser....
};
User getUserbyId(QString);


#endif // USER_H
