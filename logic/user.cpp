#include "user.h"
#include "../initialize.h"
#include <tr1/unordered_map>

using namespace std;

User::User()
{
}

void User::setUser(QString Id, QString FirstName, QString LastName, QString phone, QString otherContact, std::tr1::unordered_map<QString, userCar> userCar)
{
    this->id = Id;
    this->firstName = FirstName;
    this->lastName = LastName;
    this->phone = phone;
    this->otherContact = otherContact;
    this->userCarsHash = userCar;
}

void User::setUser(QString Id, QString FirstName, QString LastName, QString phone, QString otherContact, QString notes, std::tr1::unordered_map<QString, userCar> userCar)
{
    this->id = Id;
    this->firstName = FirstName;
    this->lastName = LastName;
    this->phone = phone;
    this->otherContact = otherContact;
    this->notes = notes;
    this->userCarsHash = userCar;
}
