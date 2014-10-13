#ifndef INITIALIZE_H
#define INITIALIZE_H
#include <string>
#include "logic/usercar.h"
#include "logic/user.h"
#include <tr1/unordered_map>
#include "extensions.h"

using namespace std;

class initialize
{
private:
    std::tr1::unordered_map<QString, User> UsersHash;
    static initialize* m_usersInstance;
public:
    initialize();
    static initialize* Instance();
    void initializeUsersHash();
    std::tr1::unordered_map<QString, User> getUsersHash();
    void addUserToHash(QString Id, QString FirstName, QString LastName, QString phone, QString otherContact, QString notes);


};

#endif // INITIALISE_H
