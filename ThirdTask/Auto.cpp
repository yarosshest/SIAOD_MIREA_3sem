//
// Created by yaros on 21.09.2022.
//

#include "Auto.h"

Auto::Auto(vector<char *> data) {
    strcpy(region, data[0]);
    strcpy(num, data[1]);
    strcpy(characters, data[2]);
    strcpy(model, data[3]);
    strcpy(color, data[4]);
    strcpy(name, data[5]);
    strcpy(surname, data[6]);
    strcpy(address, data[7]);
    strcpy(date, data[8]);
}

string Auto::toString() {
    string s = "";
    s += region;
    s += " ";
    s += num;
    s += " ";
    s += characters;
    s += " ";
    s += model;
    s += " ";
    s += color;
    s += " ";
    s += name;
    s += " ";
    s += surname;
    s += " ";
    s += address;
    s += " ";
    s += date;
    return s;
}

string Auto::out() {
    string s = "region: ";
    s += region;
    s += " num: ";
    s += num;
    s += " characters: ";
    s += characters;
    s += " model: ";
    s += model;
    s += " color: ";
    s += color;
    s += " name: ";
    s += name;
    s += " surname: ";
    s += surname;
    s += " address: ";
    s += address;
    s += " date: ";
    s += date;
    return s;
}

bool Auto::operator==(const Auto& rhs) const {
    return model == rhs.model &&
           color == rhs.color &&
           date == rhs.date &&
           region == rhs.region &&
           num == rhs.num &&
           characters == rhs.characters &&
           name == rhs.name &&
           surname == rhs.surname &&
           address == rhs.address;
}

Auto::Auto() {
    strcpy(model, "");
    strcpy(color, "");
    strcpy(date, "");
    strcpy(region, "");
    strcpy(num, "");
    strcpy(characters, "");
    strcpy(name, "");
    strcpy(surname, "");
    strcpy(address, "");
}

char* Auto::getNumber() {
    char *s = new char[600];
    strcpy(s, region);
    strcat(s, num);
    strcat(s, characters);
    return s;
}
