//
// Created by yaros on 28.10.2022.
//

#include "Data.h"

int Data::getNum() {
    return stoi(num);
}

Data::Data(char num[200], char name[200], char address[200]) {
    strcpy_s(this->num, num);
    strcpy_s(this->name, name);
    strcpy_s(this->address, address);
    this->shift = -1;
}

bool Data::operator==(const Data &a) const {
    return stoi(num) == stoi(a.num);
}

bool Data::operator!=(const Data &a) const {
    return stoi(num) != stoi(a.num);
}

bool Data::operator>(const Data &a) const {
    return stoi(num) > stoi(a.num);
}

bool Data::operator<(const Data &a) const {
    return stoi(num) < stoi(a.num);
}

bool Data::operator>=(const Data &a) const {
    return stoi(num) >= stoi(a.num);
}

bool Data::operator<=(const Data &a) const {
    return stoi(num) <= stoi(a.num);
}
Data::Data(vector<char*> data){
    strcpy_s(this->num, data[0]);
    strcpy_s(this->name, data[1]);
    strcpy_s(this->address, data[2]);
}

Data::Data() {
    strcpy_s(num, "-");
    strcpy_s(name, "-");
    strcpy_s(address, "-");
}


Data::Data(bool ui) {
    if (ui){
        cout << "Enter num: ";
        cin >> num;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
    }

}

string Data::print() {
    return string(num) + " " + string(name) + " " + string(address);
}

int Data::getShift() {
    return shift;
}

void Data::setShift(int shift) {
    this->shift = shift;
}

void Data::setNum(char *num) {
    strcpy_s(this->num, num);
}

