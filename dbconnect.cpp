#include <QCoreApplication>
#include "dbconnect.h"
#include <QtSql>

QSqlDatabase db;

bool createConnection()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("pnote");
    db.setUserName("marc"); db.setPassword("marc");
    db.open();
    return true;
}

QString getTextFromQuery()
{
    QSqlQuery query;
    QString textFile;
    query.exec("SELECT location FROM files;");
    while (query.next()){
        textFile = query.value(0).toString();

    }
    return textFile;
}

bool closeConnection()
{
    db.close();
    return true;
}
