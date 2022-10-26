//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_NODE_H
#define SIAOD_NODE_H

#include <iostream>
#include <clocale>
#include <sstream>
#include <vector>
using namespace std;
class node {
public:
    char info = NULL;
    node *l = nullptr;
    node *r = nullptr;
    explicit node(vector<char> &keys);
    int height(char x);
    int countChild();
    void print(string &resul);
};


#endif //SIAOD_NODE_H
