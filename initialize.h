#ifndef INITIALIZE_H
#define INITIALIZE_H
#include <string>
#include "usercar.h"
#include "user.h"
#include <tr1/unordered_map>

using namespace std;

class initialize
{
private:
    std::tr1::unordered_map<string, User> UsersHash;
    static initialize* m_usersInstance;
public:
    initialize();
    static initialize* Instance();
    void initializeUsersHash();
    std::tr1::unordered_map<string, User> getUsersHash();

};

#endif // INITIALISE_H
