#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <QString>

class utilities
{
public:
    utilities();
    void generateString(char* s,int len);
    std::string saveImage(QString oldPath);

};

#endif // UTILITIES_H
