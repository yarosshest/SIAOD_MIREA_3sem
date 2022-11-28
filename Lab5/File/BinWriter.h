//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_BINWRITER_H
#define SIAOD_BINWRITER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include "../Data.h"

using namespace std;
class BinWriter {

public:
    void writeBin(string name, string nameBin);
    void writeSource(string nameBin, string src);
    void readBin(string name, vector<Data> &Datas);
    void writeData(string name, Data au, int index);
    void outputBin(string name);
    static Data* readData(string name, int index);
    void dellData(string name, int index);
    static int addData(string name, Data au);
    void rep(string date,string reg ,string num, string buk, string name);
    void showMod(string date,string mod ,string name);
    static bool fileCheck(string name) ;
    int getIndexById(string name, int id);
    Data findByKey(string name, int num);
};


#endif //SIAOD_BINWRITER_H
