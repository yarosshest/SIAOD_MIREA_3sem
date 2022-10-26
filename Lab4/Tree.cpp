//
// Created by yaros on 26.10.2022.
//

#include "Tree.h"

void Tree::add(char n) {
    if (root == nullptr) {
        root = new node;
        root->info = n;
        return;
    }
    root = root->add(n);
}

string Tree::print() {
    balance();
    if (root == nullptr) {
        return "Tree is empty";
    }
    string result;
    result.append("https://quickchart.io/graphviz?graph=digraph{");
    root->print(result);
    result.append("}");
    return result;
}

void Tree::balance() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }

    root = root->balance();
}
