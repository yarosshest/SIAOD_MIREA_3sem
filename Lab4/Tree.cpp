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

void Tree::print() {
    balance();
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root->print();
}

void Tree::balance() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root = root->balance();
}
