//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_NODEAVL_H
#define SIAOD_NODE_H

#include <iostream>
#include <clocale>
#include <sstream>
#include <vector>
using namespace std;
class nodeAVL {
public:
    char info = NULL;
    nodeAVL *l = nullptr;
    nodeAVL *r = nullptr;
    explicit nodeAVL(vector<char> &keys);
    int height(char x);
    int countChild();
    void print(string &resul);
    void printLeft(string const & rpref = "", string const & cpref = "", string const & lpref = "");
    void printhight(std::string const & prefix = "", bool root = true, bool last = true);
};


#endif //SIAOD_NODEAVL_H
