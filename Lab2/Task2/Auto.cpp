//
// Created by yaros on 21.09.2022.
//

#include "Auto.h"

Auto::Auto(vector<char *> data) {
    id = string(data[0]);
    region  = string(data[1]);
    num = string(data[2]);
    characters = string(data[3]);
    model = string(data[4]);
    color = string(data[5]);
    surname = string(data[6]);
    name = string(data[7]);
    address = string(data[8]);
    date = string(data[9]);
}

string Auto::toString() {
    return id + ";" + region + ";" + num + ";" + characters + ";" + model + ";" + color + ";" + surname + ";" + name + ";" + address + ";" + date;
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
    id = "";
    model = "";
    color = "";
    date = "";
    region = "";
    num = "";
    characters = "";
    name = "";
    surname = "";
    address = "";
}
