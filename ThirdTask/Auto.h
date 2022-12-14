//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_AUTO_H
#define SIAOD_AUTO_H

#include <string>
#include <vector>
#include <cstring>
using namespace std;
class Auto {
public:
    char id[200];
    char model[200];
    char color[200];
    char date[200];
    char region[200];
    char num[200];
    char characters[200];
    char name[200];
    char surname[200];
    char address[200];
    explicit Auto(vector<char*> data);
    Auto();
    string toString();
    bool operator==(const Auto& a) const;
    string out();
};


#endif //SIAOD_AUTO_H
