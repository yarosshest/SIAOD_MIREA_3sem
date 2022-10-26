//
// Created by yaros on 26.10.2022.
//

#ifndef SIAOD_NODE_H
#define SIAOD_NODE_H

#include <iostream>
#include <clocale>
using namespace std;
class node {
public:
    char info = NULL;
    int height  = 0;
    node *l = nullptr;
    node *r = nullptr;
    int balance_factor();
    void fix_height();
    node *rotate_right();
    node *rotate_left();
    node *balance();
    node *add(char x);
    void print(string const & rpref = "", string const & cpref = "", string const & lpref = "");
};


#endif //SIAOD_NODE_H
