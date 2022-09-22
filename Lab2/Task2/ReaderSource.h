//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_READERSOURSE_H
#define SIAOD_READERSOURSE_H

#include "Auto.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class ReaderSource {
public:
    vector<Auto> readSource(string name);
    void writeSource(string name, vector<Auto> autos);
};


#endif //SIAOD_READERSOURSE_H
