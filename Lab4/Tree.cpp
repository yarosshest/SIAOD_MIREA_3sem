//
// Created by yaros on 26.10.2022.
//

#include "Tree.h"
string Tree::print() {
    if (root == nullptr) {
        return "Tree is empty";
    }
    string result;
    result.append("https://quickchart.io/graphviz?graph=digraph{");
    root->print(result);
    result.append("}");
    return result;
}

Tree::Tree(vector<char> &keys) {
    root = new node(keys);
}

int Tree::height(char x) {
    return root->height(x);
}

int Tree::countLeft() {
    return root->l->countChild() +1;
}
