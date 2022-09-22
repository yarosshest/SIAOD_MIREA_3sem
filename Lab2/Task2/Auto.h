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
    string id;
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
    Auto();
    string toString();
    bool operator==(const Auto& a) const;
};


#endif //SIAOD_AUTO_H
