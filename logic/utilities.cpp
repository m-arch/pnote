#include "utilities.h"
#include <stdlib.h>     /* srand, rand */
#include <QDir>

utilities::utilities()
{
}


void utilities::generateString(char* s, int len )
{
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < len; ++i) {
            s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }
}

std::string utilities::saveImage(QString oldPath)
//This function takes an image from old path and saves it to public/images directory
//under a randomly generated 32 charachters alpha numeric name
//returns the new location in case of success
{
    std::string newPath;
    char* newFile = new char[32];
    generateString(newFile, 32);
    QDir dir("public/images");
    if(!dir.exists()) {
        dir.mkpath(".");
    }
    newPath = dir.path().toStdString() + "/" + newFile;
    QFile::copy(oldPath, QString::fromStdString(newPath));
    return newPath;
}
