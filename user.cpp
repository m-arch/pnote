#include "user.h"
using namespace std;

User::User()
{
}

void User::setUser(string Id, string FirstName, string LastName, string phone)
{
    this->id = Id;
    this->firstName = FirstName;
    this->lastName = LastName;
    this->phone = phone;
}
