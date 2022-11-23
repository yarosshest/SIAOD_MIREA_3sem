//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_NODE_H
#define SIAOD_NODE_H

#include <iostream>
#include "../Data.h"
#include <clocale>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
class node {
public:
    Data info = Data();
    node *l = nullptr;
    node *r = nullptr;
    explicit node(vector<Data> &keys);
    int height(Data x);
    int countChild();
    void print(string &resul);
    void printLeft(string const & rpref = "", string const & cpref = "", string const & lpref = "");
    void printhight(std::string const & prefix = "", bool root = true, bool last = true);
    Data findByKey(int key);
};


#endif //SIAOD_NODE_H
