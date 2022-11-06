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

Tree::Tree(vector<char> k) {
    keys = k;
    root = new node(keys);
}

int Tree::height(char x) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    if (find(keys.begin(), keys.end(), x) != keys.end())
        return root->height(x);
    else{
        cout << "Element not found" << endl;
        return -1;
    }
}

int Tree::countLeft() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    return root->l->countChild() +1;
}

void Tree::printLeft() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root->printLeft();
}

void Tree::printHigh() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root->printhight();
}

Tree::Tree() {
    root = nullptr;
}
