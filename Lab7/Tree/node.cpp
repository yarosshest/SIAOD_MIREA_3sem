//
// Created by yaros on 26.10.2022.
//

#include "node.h"
//Конструктор узла по вектору ключей
//Если вектор  ключей содержит 1 элемент, то узел является листом. Иначе если вектор ключей содержит 2 элемента,
// то создаться левый лист с ключем по индексу 0 а ключ  по индексу 1 присваивается  полю info узла.
// Если вектор ключей , больше 2 элементов, то создаться левый узел с ключами от 0 до середины вектора ключей,
// середина вектора ключей присваивается полю info узла, а правый узел создаётся  с ключами от середины вектора ключей до конца вектора ключей.
node::node(vector<record> &keys) {
    if (keys.size() == 1)
        info = {keys[0]};
    else if (keys.size() == 2) {
        info = {keys[0],keys[1]};
        vector<record> left = {keys[0]};
        vector<record> right = {keys[1]};

        l = new node(left);
        r = new node(right);
    }
    else {
        info = keys;

        vector<record> leftC;
        vector<record> rightC;
        balance(keys, leftC, rightC);

        l = new node(leftC);
        r = new node(rightC);
    }
}

//Метод вывода дерева слева на право
//Если существует правый узел, то выводится правый узел, затем выводится ключ узла, затем выводится левый узел.
void node::printLeft(string const & rpref, string const & cpref, string const & lpref ) {
    if (r)
        r->printLeft(rpref + "  ", rpref + "/-", rpref + "| ");
    cout << cpref;
    wstring ws;
    for(record r : info) {
        ws += r.getKey();
    }
    wcout << ws << endl;
    cout << endl;
    if (l)
        l->printLeft( lpref + "| ", lpref + "\\-", lpref + "  ");
}

int sum(vector<record> keys){
    int sum = 0;
    for(record r : keys)
        sum += r.getVal();
    return sum;
}

void node::balance(vector<record> keys, vector<record> &lef, vector<record> &right) {
    sort(keys.begin(), keys.end(), greater<>());
    for(record r : keys) {
        if (sum(lef) < sum(right)) {
            lef.push_back(r);
        } else {
            right.push_back(r);
        }
    }
}

void node::getCodes(map<wchar_t, string> &codes, string path) {
    if (info.size() > 1){
        if (l)
            l->getCodes(codes, path + "0");
        if (r)
            r->getCodes(codes, path + "1");
    } else
        codes[info[0].getKey()] = path;
}



