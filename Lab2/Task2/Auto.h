//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_AUTO_H
#define SIAOD_AUTO_H

#include <string>
using namespace std;

struct number {
    int region;
    int number;
    string characters;
};

struct holder {
    string name;
    string surname;
    string address;
};

class Auto {
private:
    string model;
    string color;
    string date;
    number num;
    holder hold;
public:
    Auto(string model, string color, string date, number num, holder hold);
};


#endif //SIAOD_AUTO_H
