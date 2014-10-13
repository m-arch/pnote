#ifndef EXTENSIONS_H
#define EXTENSIONS_H
#include <QString>
#include <tr1/unordered_map>

namespace std
{
    namespace tr1
    {
        template <>
        struct hash<QString>
        {
            size_t operator()(const QString& v) const
            {
                size_t tmpString = hash<string>()(v.toStdString());
                return tmpString;
            }
        };
     }
}
#endif // EXTENSIONS_H
