//
// Created by yaros on 28.10.2022.
//

#ifndef SIAOD_DATA_H
#define SIAOD_DATA_H
#include <string>
#include <vector>
using namespace std;
class Data {
public:
    basic_string<char> num;
    string name;
    string address;
    Data();
    Data(int num, string name, string address);
    explicit Data(vector<char*> data);
    bool operator==(const Data& a) const;
    bool operator!=(const Data& a) const;
    bool operator>(const Data& a) const;
    bool operator<(const Data& a) const;
    bool operator>=(const Data& a) const;
    bool operator<=(const Data& a) const;

};


#endif //SIAOD_DATA_H
