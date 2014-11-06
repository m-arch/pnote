    #include "initialize.h"
#include <QCoreApplication>
#include "logic/dbconnect.h"
#include <QtSql>
#include <stddef.h>  // defines NULL

initialize* initialize::m_usersInstance = NULL;

initialize::initialize()
{
    if(!m_usersInstance){
        createConnection();
        this->initializeUsersHash();
        closeConnection();
    }
}

initialize* initialize::Instance()
{
    if(!m_usersInstance)
        m_usersInstance = new initialize;

    return m_usersInstance;
}

void initialize::initializeUsersHash()
{
    QSqlQuery query;
    User tmpUser;
    QString previousId = "";
    std::tr1::unordered_map<int, userCar> userCarsHash;
    QString Id, firstName, lastName, phone, other, notes;
    query.exec("SELECT ID, First_Name, Last_Name, Contact_Number, Other_Contact, Notes FROM pnote.user;");
    while (query.next()){
        userCar tmpCar;
        Id = query.value(0).toString().trimmed();
        firstName = query.value(1).toString().trimmed();
        lastName = query.value(2).toString().trimmed();
        phone = query.value(3).toString().trimmed();
        other = query.value(4).toString().trimmed();
        notes = query.value(5).toString().trimmed();
        userCarsHash =  tmpCar.makeUserCarsHash(Id);
        tmpUser.setUser(Id, previousId, firstName, lastName, phone, other, notes, userCarsHash);
        this->UsersHash.insert(std::make_pair(Id, tmpUser));
        if (previousId != "")
        {
            User hashUser = this->UsersHash[previousId];
            if (this->firstUser.nextId == "")
                this->firstUser.nextId = Id;

            hashUser.nextId = Id;
            this->UsersHash[previousId] = hashUser;

        }
        else
            this->firstUser = tmpUser;

        previousId = Id;
        this->lastUser = tmpUser;
    }
}

void initialize::setUsersHash(std::tr1::unordered_map<QString, User> newHash)
{
    m_usersInstance->UsersHash = newHash;
}

void initialize::updateHashEntry(User updatedUser)
{
    m_usersInstance->UsersHash[updatedUser.id] = updatedUser;
}


std::tr1::unordered_map<QString, User> initialize::getUsersHash()
{
    return this->UsersHash;
}
