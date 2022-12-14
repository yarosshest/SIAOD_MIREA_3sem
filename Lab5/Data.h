//
// Created by yaros on 28.10.2022.
//

#ifndef SIAOD_DATA_H
#define SIAOD_DATA_H
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <utility>
#include <iostream>
using namespace std;
class Manager {
    char num[200];
    char name[200];
    char address[200];
    int shift = -1;
public:
    Manager();
    explicit Manager(bool ui);
    Manager(char num[200], char name[200], char address[200]);
    int getNum();
    void setNum(char num[200]);
    int getShift();
    void setShift(int shift);


    string print();
    explicit Manager(vector<char*> data);
    bool operator==(const Data& a) const;
    bool operator!=(const Data& a) const;
    bool operator>(const Data& a) const;
    bool operator<(const Data& a) const;
    bool operator>=(const Data& a) const;
    bool operator<=(const Data& a) const;
};


#endif //SIAOD_DATA_H
