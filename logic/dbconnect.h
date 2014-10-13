#ifndef DBCONNECT_H
#define DBCONNECT_H

#include <QSqlDatabase>
#include <string>
#include "../extensions.h"


bool createConnection();
bool closeConnection();
//QString getTextFromQuery();
#endif // DBCONNECT_H
