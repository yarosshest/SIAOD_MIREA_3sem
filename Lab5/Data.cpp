//
// Created by yaros on 28.10.2022.
//

#include "Data.h"

#include <utility>

Data::Data(string num, string name, string address) {
    this->num = std::move(num);
    this->name = std::move(name);
    this->address = std::move(address);
}

bool Data::operator==(const Data &a) const {
    return num == a.num && name == a.name && address == a.address;
}

bool Data::operator!=(const Data &a) const {
    return num != a.num || name != a.name || address != a.address;
}

bool Data::operator>(const Data &a) const {
    return num > a.num;
}

bool Data::operator<(const Data &a) const {
    return num < a.num;
}

bool Data::operator>=(const Data &a) const {
    return num >= a.num;
}

bool Data::operator<=(const Data &a) const {
    return num <= a.num;
}
Data::Data(vector<char*> data){
    num = string(data[0]);
    name = string(data[1]);
    address = string(data[2]);
}

Data::Data() {
    num = "-";
    name = "-";
    address = "-";
}

string Data::toString() const {
    return num;
}
