//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREEAVL_H
#define SIAOD_TREEAVL_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "nodeAVL.h"
#include "../Data.h"
using namespace std;

class TreeAVL {
    nodeAVL *root = nullptr;
public:
    explicit TreeAVL(string file);
    void add(Data x);
    string print();
    void balance();
    static vector<Data> reedFile(string path);
    static bool fileCheck(const string& name) ;
    int getCol_rotations() const;
};


#endif //SIAOD_TREEAVL_H
