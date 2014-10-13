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
    std::tr1::unordered_map<QString, userCar> userCarsHash;
    QString Id, firstName, lastName, phone, other;
    query.exec("SELECT ID, First_Name, Last_Name, Contact_Number, Other_Contact FROM pnote.user;");
    while (query.next()){
        userCar tmpCar;
        Id = query.value(0).toString();
        firstName = query.value(1).toString();
        lastName = query.value(2).toString();
        phone = query.value(3).toString();
        other = query.value(4).toString();
        userCarsHash =  tmpCar.makeUserCarsHash(Id);
        tmpUser.setUser(Id, firstName, lastName, phone, other, userCarsHash);
        this->UsersHash.insert(std::make_pair(Id, tmpUser));
    }
}

void initialize::addUserToHash(QString Id, QString FirstName, QString LastName, QString phone, QString otherContact, QString notes)
{
    User tmpUser;
    tmpUser.id = Id;
    tmpUser.firstName = FirstName;
    tmpUser.lastName = LastName;
    tmpUser.phone = phone;
    tmpUser.otherContact = otherContact;
    tmpUser.notes = notes;
    if(!m_usersInstance)
        m_usersInstance = new initialize;

    m_usersInstance->UsersHash.insert(std::make_pair(Id, tmpUser));
}


std::tr1::unordered_map<QString, User> initialize::getUsersHash()
{
    return this->UsersHash;
}
