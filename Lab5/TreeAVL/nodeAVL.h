//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_NODEAVL_H
#define SIAOD_NODEAVL_H

#include <iostream>
#include <clocale>
#include <sstream>
using namespace std;
class nodeAVL {
public:
    char info = NULL;
    int height  = 1;
    nodeAVL *l = nullptr;
    nodeAVL *r = nullptr;
    int balance_factor();
    void fix_height();
    nodeAVL *rotate_right();
    nodeAVL *rotate_left();
    nodeAVL *balance();
    nodeAVL *add(char x);
    void print(string &resul);
};


#endif //SIAOD_NODEAVL_H
