#include "utilities.h"
#include <stdlib.h>     /* srand, rand */

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
