//
// Created by yaros on 28.10.2022.
//

#ifndef SIAOD_DATA_H
#define SIAOD_DATA_H
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
using namespace std;
class Data {
    char num[200];
    char name[200];
    char address[200];
public:
    Data();
    explicit Data(bool ui);
    Data(char num[200], char name[200], char address[200]);

    void setNum(char num[200]);
    void setName(char name[200]);
    void setAddress(char address[200]);
    int getNum();
    string getName();
    string getAddress();

    string print();
    explicit Data(vector<char*> data);
    bool operator==(const Data& a) const;
    bool operator!=(const Data& a) const;
    bool operator>(const Data& a) const;
    bool operator<(const Data& a) const;
    bool operator>=(const Data& a) const;
    bool operator<=(const Data& a) const;
    [[nodiscard]] string toString() const;

};


#endif //SIAOD_DATA_H
