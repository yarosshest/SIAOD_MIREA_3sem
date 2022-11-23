//
// Created by yaros on 26.10.2022.
//

#include "Tree.h"

#include <utility>
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
        return false;
    }else{
        fileSrc.close();
        return true;
    }
}

Tree::Tree(string pat) {
    keys = reedFile(std::move(pat));
    sort(keys.begin(), keys.end());
    root = new node(keys);
}

void Tree::dell(string key) {
    Data x = Data();
    x.setNum(reinterpret_cast<char *>(stoi(key)));
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    if (find(keys.begin(), keys.end(), x) != keys.end()) {
        keys.erase(find(keys.begin(), keys.end(), x));
        root = new node(keys);
    } else{
        cout << "Element not found" << endl;
    }
}

Data Tree::findByKey(int key) {
    return root->findByKey(key);
}

void Tree::add(Data x) {
    if (find(keys.begin(), keys.end(), x) != keys.end()) {
        cout << "Element already exists" << endl;
        return;
    }
    keys.push_back(x);
    root = new node(keys);
}
