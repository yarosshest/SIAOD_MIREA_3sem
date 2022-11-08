//
// Created by yaros on 26.10.2022.
//

#include "Tree.h"

#include <utility>
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

Tree::Tree(vector<Data> k) {
    keys = std::move(k);
    root = new node(keys);
}

int Tree::height(Data x) {
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

vector<Data> Tree::reedFile(string path) {
    vector<Data> res;
    if (fileCheck(path))
    {
        ifstream file (path, ios::in);
        string line;
        while (getline(file, line)) {
            vector<char *> data = vector<char *>();
            char *str = const_cast<char *>(line.c_str());

            char *tmp_char = strtok(str, ";");

            while (tmp_char != NULL && *(tmp_char) != '\r') {
                data.push_back(tmp_char);
                tmp_char = strtok(NULL, ";");
            }
            res.emplace_back(data);
        }
        file.close();
        sort(res.begin(), res.end());
    }
    return res;
}

bool Tree::fileCheck(const string& name) {
    ifstream fileSrc(name);
    if (!fileSrc)
    {
        cout << "File doesn't exist\n";
        fileSrc.close();
        return false;
    }else{
        fileSrc.close();
        return true;
    }
}

Tree::Tree(string pat) {
    keys = reedFile(std::move(pat));
    root = new node(keys);
}
