//
// Created by yaros on 21.09.2022.
//

#include "Auto.h"

Auto::Auto(vector<char *> data) {
    region  = string(data[0]);
    num = string(data[1]);
    characters = string(data[2]);
    model = string(data[3]);
    color = string(data[4]);
    surname = string(data[5]);
    name = string(data[6]);
    address = string(data[7]);
    date = string(data[8]);
}
