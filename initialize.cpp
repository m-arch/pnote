#include "initialize.h"
#include <QCoreApplication>
#include "logic/dbconnect.h"
#include <QtSql>
#include <stddef.h>  // defines NULL

initialize* initialize::m_usersInstance = NULL;

initialize::initialize()
{
    createConnection();
    this->initializeUsersHash();
    closeConnection();
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
    std::string Id, firstName, lastName, phone;
    query.exec("SELECT ID, First_Name, Last_Name, Contact_Number FROM pnote.user;");
    while (query.next()){
        Id = query.value(0).toString().toStdString();
        firstName = query.value(1).toString().toStdString();
        lastName = query.value(2).toString().toStdString();
        phone = query.value(3).toString().toStdString();
        tmpUser.setUser(Id, firstName, lastName, phone);
        this->UsersHash.insert(std::make_pair(Id, tmpUser));
    }
}


std::tr1::unordered_map<string, User> initialize::getUsersHash()
{
    return this->UsersHash;
}
