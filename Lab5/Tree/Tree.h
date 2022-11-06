//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREEAVL_H
#define SIAOD_TREE_H
#include <iostream>
#include "node.h"
using namespace std;

class TreeAVL {
    nodeAVL *root = nullptr;
    vector<char> keys;
public:
    TreeAVL();
    explicit TreeAVL(vector<char> k);
    string print();
    int height(char x);
    int countLeft();
    void printLeft();
    void printHigh();
};


#endif //SIAOD_TREEAVL_H
