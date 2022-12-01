//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_NODE_H
#define SIAOD_NODE_H

#include <iostream>
#include <clocale>
#include <sstream>
#include <vector>
#include "record.h"
#include <map>
using namespace std;
class node {
public:
    vector<record> info;
    explicit node(vector<record> &keys);
    node(vector<record> k, node *l, node *r);
    node *l = nullptr;
    node *r = nullptr;
    void getCodes(map<wchar_t, string> &codes, string path);
    int getWeight();
    void balance(vector<record> keys, vector<record> &lef, vector<record> &right);
    void printLeft(string const & rpref = "", string const & cpref = "", string const & lpref = "");
};


#endif //SIAOD_NODE_H
