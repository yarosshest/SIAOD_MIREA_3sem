//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREEAVL_H
#define SIAOD_TREEAVL_H
#include <iostream>
#include "nodeAVL.h"
using namespace std;

class TreeAVL {
    nodeAVL *root = nullptr;
public:
    void add(char x);
    string print();
    void balance();

};


#endif //SIAOD_TREEAVL_H
