#ifndef USER_H
#define USER_H
#include <string>
#include "usercar.h"
#include <tr1/unordered_map>

using namespace std;

class User
{
private:


public:
    User();
    User getUserbyId(string);
    void setUser(string, string, string, string);
    void getUsersHash();
    void insertUser(string, string, string, string, string, string);
    void deleteUser(string);
    string id, firstName, lastName, phone, otherContact, notes;
    std::tr1::unordered_map<string, userCar> userCarsHash;
    //void updateUser....
};

#endif // USER_H
