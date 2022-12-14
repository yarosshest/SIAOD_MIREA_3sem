//
// Created by yaros on 21.09.2022.
//

#include "Auto.h"

Auto::Auto(vector<char *> data) {
    strcpy(id, data[0]);
}

string Auto::toString() {
    string s = "";
    s += id;
    s += " ";
    s += model;
    s += " ";
    s += color;
    s += " ";
    s += date;
    s += " ";
    s += region;
    s += " ";
    s += num;
    s += " ";
    s += characters;
    s += " ";
    s += name;
    s += " ";
    s += surname;
    s += " ";
    s += address;
    return s;
}

string Auto::out() {
    string s = "region: ";
    s += region;
    s += " num: ";
    s += num;
    s += " characters: ";
    s += characters;
    s += " date: ";
    s += date;
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
    return s;
}

bool Auto::operator==(const Auto& rhs) const {
    return id == rhs.id &&
           model == rhs.model &&
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
    strcpy(id, "");
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
