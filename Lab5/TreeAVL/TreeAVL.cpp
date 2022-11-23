//
// Created by yaros on 26.10.2022.
//

#include "TreeAVL.h"
//Метод для добавления элемента в дерево
//Если корень пустой, то создаем новый узел и приравниваем его к корню дерева, если нет, то вызываем рекурсивную функцию для добавления элемента
void TreeAVL::add(Data n) {
    if (root == nullptr) {
        root = new nodeAVL;
        root->info = n;
        return;
    }
    root = root->add(n);
}
//Метод для нахождения элемента в дереве
//Если корень пустой, то возвращаем пустой элемент, если нет, если элемента нет в ключах то возвращаем пустой элемент,
// если нет, то вызываем рекурсивную функцию для поиска элемента
Data TreeAVL::find(int x) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return Data();
    }
    nodeAVL *temp = root->find(x);
    if (temp == nullptr) {
        cout << "Element not found" << endl;
        return Data();
    }
    return temp->info;
}
//Метод для вывода дерева
//Если корень пустой, то выводим сообщение, если нет, то вызываем рекурсивную функцию для вывода дерева
void TreeAVL::print() {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
    }
    else
        root->print("", "", "");
}
//Метод для чтения файла
//Если файл существует, то открываем его, считываем данные и добавляем их в вектор который возвращаем.
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


//Конструктор класса из файла
//Если файл существует, то считываем данные из файла и добавляем их в дерево
TreeAVL::TreeAVL(string file) {
    vector<Data> keys = reedFile(std::move(file));
    for (auto &key : keys) {
        add(key);
    }
    col_keys = keys.size();
}

//Метод для проверки существования файла
//Если файл существует, то возвращаем true, если нет, то выводим сообщение и возвращаем false
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

//Метод подсчета количества поворотов
//Если корень пустой, то возвращаем 0, если нет, то вызываем рекурсивную функцию для подсчета количества поворотов
int TreeAVL::getCol_rotations() const {
    if (root == nullptr)
        return 0;
    else
        return root->getCol_rotations();
}

//Метод удаления элемента из дерева
//Если корень пустой, то выводим сообщение, если нет, то вызываем рекурсивную функцию для удаления элемента
void TreeAVL::dell(int x) {
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    root = root->dell(x);
}


//Метод подсчета среднего количества поворотов при добавлении элемента
//Если корень пустой, то возвращаем 0, если нет, то вызываем рекурсивную функцию для подсчета среднего количества поворотов при добавлении элемента и делим на количество элементов
double TreeAVL::median_rotations() {
    return (double)getCol_rotations() / col_keys;
}
