#ifndef DBSETUP_H
#define DBSETUP_H

#include "dbconnect.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>

class dbSetup
{
public:
    dbSetup();

private:
    bool setupTablesdb();
};

#endif // DBSETUP_H
