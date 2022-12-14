//
// Created by yaros on 14.12.2022.
//
#include "BinWriter.h"
#include <iostream>
#include "../Auto.h"
int testBin(){
    BinWriter bw("test.bin");
    bw.writeBin(R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\ThirdTask\txt.txt)");
    bw.outputBin();
    cout << "====================" << endl;
    char test[200] = "test";
    char testN[200] = "6";
    vector<char*> data = vector<char*>();
    data.push_back(testN);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    data.push_back(test);
    Auto au = Auto(data);
    bw.addAuto(au);
    bw.outputBin();
    cout << "====================" << endl;
    bw.dellAuto(5);
    bw.outputBin();
    cout << "====================" << endl;
    Auto out = *bw.readAuto(5);
    cout << out.out() << endl;

}