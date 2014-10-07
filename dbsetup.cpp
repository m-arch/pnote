#include "dbsetup.h"
#include "dbconnect.h"
#include <QCoreApplication>
#include <QtSql>


QString scriptFile = "db-setup/setup.sql";

dbSetup::dbSetup()
{
    createConnection();
    setupTablesdb();
    closeConnection();
}


bool dbSetup::setupTablesdb()
{
    int tmplength;
    QString tmpLine = "";
    QString path = ":/";
    path += scriptFile;
    QSqlQuery query;
    QFile inputFile(path);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&inputFile);
    while(!in.atEnd())
    {
        QString line = in.readLine(); //reads one line at a time
        tmplength = line.length() - 1;
        if (line != "")
        {
            QChar lastChar = line.at(tmplength);
            if (lastChar != QChar(59))  //59 is the unicode representation of ;
                tmpLine.append(line);
            else
                if (tmpLine != "")
                {
                    tmpLine.append(line);
                    query.exec(tmpLine);
                    tmpLine = "";
                }
                else
                    query.exec(line);
        }
    }
    inputFile.close();
    return true;
}
