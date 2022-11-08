//
// Created by yaros on 26.10.2022.
//

#include "TreeAVL.h"

void TreeAVL::add(Data n) {
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
vector<Data> TreeAVL::reedFile(string path) {
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
    }
    return res;
}

TreeAVL::TreeAVL(string file) {
    vector<Data> keys = reedFile(std::move(file));
    for (auto &key : keys) {
        add(key);
    }
}

bool TreeAVL::fileCheck(const string& name) {
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

int TreeAVL::getCol_rotations() const {
    if (root == nullptr)
        return 0;
    else
        return root->getCol_rotations();
}
