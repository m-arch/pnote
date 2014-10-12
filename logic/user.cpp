#include "user.h"
using namespace std;

User::User()
{
}

void User::setUser(string Id, string FirstName, string LastName, string phone, string otherContact, std::tr1::unordered_map<string, userCar> userCar)
{
    this->id = Id;
    this->firstName = FirstName;
    this->lastName = LastName;
    this->phone = phone;
    this->otherContact = otherContact;
    this->userCarsHash = userCar;
}
