//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_TREE_H
#define SIAOD_TREE_H
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <fstream>
#include "algorithm"
#include "node.h"
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Tree {
    node *root = nullptr;
    vector<Data> keys;
public:
    Tree();
    explicit Tree(vector<Data> k);
    explicit Tree(string path);
    string print();
    int height(Data x);
    int countLeft();
    void printLeft();
    void printHigh();
    static bool fileCheck(const string& name) ;
    static vector<Data> reedFile(string path);
    void dell(string key);
};


#endif //SIAOD_TREE_H
