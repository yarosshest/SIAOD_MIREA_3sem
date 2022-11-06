//
// Created by yaros on 30.09.2022.
//

#ifndef SIAOD_UI_H
#define SIAOD_UI_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Tree/Tree.h"
using namespace std;
class UI {
private:
    string name;
    string nameOut;
    string line;
    int task;
    int index;
    bool isExit = false;
    int n;
    string menu = "1. Creating a tree\n"
                  "2. Determine the level at which the value is set\n"
                  "3. Determine the number of characters in the left subtree of the source tree\n"
                  "4. Display the tree on the screen by turning it anticlockwise\n"
                  "5. Output the tree by placing the elements vertically\n";
public:
    void start();
};


#endif //SIAOD_UI_H
