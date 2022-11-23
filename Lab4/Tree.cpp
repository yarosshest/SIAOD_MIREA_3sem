//
// Created by yaros on 26.10.2022.
//

#include "Tree.h"

//Конструктор дерева по вектору ключей
//Поле keys заполняется вектором ключей, корню присваивается значение элемента с ключами
Tree::Tree(vector<char> k) {
    keys = k;
    root = new node(keys);
}

//Функция подсчёта  уровня узла
//Ссылка на корень дерева проверяется  на nullptr если не nullptr, если узел есть в дереве, то вызывается функция подсчета уровня узла
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
//Функция для подсчета количества левых узлов в поддереве исходного дерева.
//Ссылка на корень дерева проверяется  на nullptr если не nullptr, то  в левом поддереве вызывается функция countChild
int Tree::countLeft() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    return root->l->countChild() +1;
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

//Вывод дерева с верху вниз
//Ссылка на корень дерева проверяется на nullptr если не nullptr, то вызывается метод printHigh
void Tree::printHigh() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root->printhight();
}

//Конструктор пустого дерева
//Ссылка на корень дерева приравнивается к nullptr
Tree::Tree() {
    root = nullptr;
}
