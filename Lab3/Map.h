//
// Created by yaros on 13.10.2022.
//

#ifndef SIAOD_MAP_H
#define SIAOD_MAP_H

#include <iostream>
#include <string>
#include <vector>
struct record {
    int key;
    int line;
};



using namespace std;
class Map {
private:
    vector<record> table;

public:
    string name;
    Map();
};


#endif //SIAOD_MAP_H
