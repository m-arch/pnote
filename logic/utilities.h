#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <QString>
#include <QPixmap>

void generateString(char* s,int len);
std::string saveImage(QString oldPath);
QPixmap getPixmapfromURL(QString);
#endif // UTILITIES_H
