//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_AUTO_H
#define SIAOD_AUTO_H

#include <string>
#include <vector>
using namespace std;
class Auto {
private:
    string model;
    string color;
    string date;
    string region;
    string num;
    string characters;
    string name;
    string surname;
    string address;
public:
    explicit Auto(vector<char*> data);
};


#endif //SIAOD_AUTO_H
