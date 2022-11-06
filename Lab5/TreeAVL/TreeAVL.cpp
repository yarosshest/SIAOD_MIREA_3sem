//
// Created by yaros on 26.10.2022.
//

#include "TreeAVL.h"

void TreeAVL::add(char n) {
    if (root == nullptr) {
        root = new nodeAVL;
        root->info = n;
        return;
    }
    root = root->add(n);
}

string TreeAVL::print() {
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

void TreeAVL::balance() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }

    root = root->balance();
}
