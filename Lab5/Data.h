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
public:
    string num;
    string name;
    string address;
    Data();
    explicit Data(bool ui);
    Data(string num, string name, string address);
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
