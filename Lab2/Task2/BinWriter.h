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
#include <filesystem>
class BinWriter {

public:
    void writeBin(string name, string nameBin);
    void writeSource(string nameBin, string src);
    void readBin(string name, vector<Auto> &autos);
    void writeAuto(string name, Auto au, int index);
    void outputBin(string name);
    Auto* readAuto(string name, int index);
    void dellAuto(string name, int index);
    void rep(string date,string reg ,string num, string buk, string name);
    void showMod(string date,string mod ,string name);
    bool fileCheck(string name) const;
    int getIndexById(string name, int id);
};


#endif //SIAOD_BINWRITER_H
