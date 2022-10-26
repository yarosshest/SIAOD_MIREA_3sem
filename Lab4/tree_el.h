//
// Created by yaros on 22.05.2021.
//

#ifndef TREE_TREE_EL_H
#define TREE_TREE_EL_H
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct node_print_state_t {
    node_print_state_t* child_state;

    bool printing_last_child;
};


class tree_el{
public:
    char m_data;
    tree_el* m_left;
    tree_el* m_right;
    bool left_tag{};
    bool right_tag{};
    int height;

    explicit tree_el(char key);
    tree_el();
    tree_el(char key,tree_el* left,tree_el* right);

    void printPath(string& result,char first,char second ,char third);
    void warePath(vector<tree_el*>&,char first,char second ,char third);
    tree_el* delete_elem(char key);


    //redefining the standard operator
    friend ostream& operator<< (ostream &out, tree_el &point);

    void fixheight();
    void print_subtree(node_print_state_t* _root_state);
    int bf();
    void wayPrintPath(string& result,char command,char first,char second ,char third);
    void wayWarePath(vector<tree_el*>&,char command,char first,char second ,char third);
    tree_el* LeftRotation();
    tree_el* RightRotation();
    tree_el* Balance();
    tree_el* reBalance();
    void GraphViz(string& result);
    tree_el *DeleteMin(tree_el *x);
    tree_el *SearchMin(tree_el *x);

    bool equal(tree_el el);

    tree_el *Insert(char k);
    char min();
};


#endif //TREE_TREE_EL_H
