#ifndef USERCAR_H
#define USERCAR_H
#include <string>
#include <tr1/unordered_map>

using namespace std;

class userCar
{
private:
    string id, userId;

public:
    userCar();
    void setCar(string, string, string, string, string, string, int);
    string brand, model, motor, photo;
    int year;
    std::tr1::unordered_map<string, userCar> makeUserCarsHash(string);

};

#endif // USERCAR_H
