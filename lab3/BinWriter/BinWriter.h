//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_BINWRITER_H
#define SIAOD_BINWRITER_H
#include "../Auto.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
class BinWriter {
    string nameBin;

public:
    explicit BinWriter(string name){
        nameBin = name;
    };
    BinWriter()= default;
    BinWriter(string name, string str);
    int GetSize() const;
    void writeBin(string name);
    void readBin( vector<Auto> &autos);
    void writeAuto(Auto au, int index);
    int addAuto(Auto au);
    void outputBin() const;
    Auto* readAuto(int index);
    void dellAuto(char* index);
    bool fileCheck(string name) const;
    int getIndexById(char* id);
    vector<Auto> getAutos();
};


#endif //SIAOD_BINWRITER_H
