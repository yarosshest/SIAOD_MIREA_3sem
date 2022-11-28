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
    int key;
    int ptr;
    int height  = 1;
    int col_rotations = 0;
    nodeAVL *l = nullptr;
    nodeAVL *r = nullptr;
    [[nodiscard]] int balance_factor() const;
    void fix_height();
    nodeAVL *rotate_right();
    nodeAVL *rotate_left();
    nodeAVL *balance();
    nodeAVL *add(int val, int uk );
    void print(string const & rpref, string const & cpref, string const & lpref );
    [[nodiscard]] int getCol_rotations() const;
    nodeAVL *find(int x);
    nodeAVL *dell(int x);
};


#endif //SIAOD_NODEAVL_H
