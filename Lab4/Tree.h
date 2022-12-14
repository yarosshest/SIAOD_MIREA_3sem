//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREE_H
#define SIAOD_TREE_H
#include <iostream>
#include "node.h"
using namespace std;

class Tree {
    node *root = nullptr;
    vector<char> keys;
public:
    Tree();
    explicit Tree(vector<char> k);
    int height(char x);
    int countLeft();
    void printLeft();
    void printHigh();
};


#endif //SIAOD_TREE_H
