//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREE_H
#define SIAOD_TREE_H
#include <iostream>
#include "node.h"
#include "record.h"
#include <map>
using namespace std;

class Tree {
    node *root = nullptr;
    vector<record> keys;
public:
    Tree();
    explicit Tree(vector<record> k);
    int countLeft();
    void printLeft();
    void printHigh();
    map<wchar_t, string> getCodes();
};


#endif //SIAOD_TREE_H
