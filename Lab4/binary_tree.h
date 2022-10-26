//
// Created by yaros on 23.05.2021.
//

#ifndef TREE_BINARY_TREE_H
#define TREE_BINARY_TREE_H

#include "tree_el.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class binary_tree {
private:
    tree_el* m_root;
    int size;
public:
    //constructors
    binary_tree();

    //standard methods
    void insert(char key);
    void delete_elem(char key);
    tree_el* find(char key);
    binary_tree where (bool(*fk)(char));
    string printPath(string path);
    string printLNR();
    void wareGraph(string path);
    binary_tree getSubtree(char key);
    string GraphViz();
    void Balance();



    //redefining the standard operator
    bool operator==(binary_tree treeE);



    //special methods
    void print();
};


#endif //TREE_BINARY_TREE_H