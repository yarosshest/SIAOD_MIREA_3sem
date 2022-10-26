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
public:
    void add(char x);
    string print();
    void balance();

};


#endif //SIAOD_TREE_H
