//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_BINWRITER_H
#define SIAOD_BINWRITER_H
#include "Auto.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
class BinWriter {

public:
    void writeBin(string name, vector<Auto> autos);
    void readBin(string name, vector<Auto> &autos);
    void writeAuto(string name, Auto au, int index);
    void outputBin(string name);
    Auto readAuto(string name, int index);
    void dellAuto(string name, int index);
};


#endif //SIAOD_BINWRITER_H
