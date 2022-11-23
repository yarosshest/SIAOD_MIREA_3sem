//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREEAVL_H
#define SIAOD_TREEAVL_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "nodeAVL.h"
#include "../Data.h"
using namespace std;

class TreeAVL {
    nodeAVL *root = nullptr;
    double col_keys = 0;
public:
    explicit TreeAVL(string file);
    void add(Data x);
    void dell(int x);
    void print();
    static vector<Data> reedFile(string path);
    static bool fileCheck(const string& name) ;
    [[nodiscard]] int getCol_rotations() const;
    double median_rotations();
    Data find(int x);
};


#endif //SIAOD_TREEAVL_H
