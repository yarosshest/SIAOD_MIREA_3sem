//
// Created by yaros on 26.10.2022.
//

#include "Tree.h"

//Конструктор дерева по вектору ключей
//Поле keys заполняется вектором ключей, корню присваивается значение элемента с ключами
Tree::Tree(vector<record> k) {
    keys = k;
    root = new node(keys);
}

//Вывод дерева слева направо
//Ссылка на корень дерева проверяется на nullptr если не nullptr, то вызывается метод printLeft
void Tree::printLeft() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root->printLeft();
}

//Конструктор пустого дерева
//Ссылка на корень дерева приравнивается к nullptr
Tree::Tree() {
    root = nullptr;
}

map<wchar_t, string> Tree::getCodes() {
    map<wchar_t, string> codes;
    root->getCodes(codes, "0");
    return codes;
}
