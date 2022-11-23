//
// Created by yaros on 26.10.2022.
//

#include "nodeAVL.h"

//Метод вычисления  фактора баланса
//Возвращает разницу между высотой правого и левого поддерева
int nodeAVL::balance_factor() const {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    return hr - hl;
}

//Метод обновления высоты узла
//Высота узла равна максимальной высоте его поддеревьев + 1
void nodeAVL::fix_height() {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    height = (hl > hr ? hl : hr) + 1;
}

//Метод правого поворота
//Создаем новый узел, который равен левому поддереву текущего узла его приравниваем к правому поддереву нового узла
// и приравниваем правый поддерево текущего узла к новому узлу вызываем метод fix_height для текущего узла и нового узла
// увеличиваем кол-во поворотов на 1 и возвращаем новый узел
nodeAVL *nodeAVL::rotate_right() {
    nodeAVL *q = l;
    l = q->r;
    q->r = this;
    fix_height();
    q->fix_height();
    col_rotations++;
    return q;
}


//Метод левого поворота
//Создаем новый узел, который равен правому поддереву текущего узла его приравниваем к левому поддереву нового узла
// и приравниваем левый поддерево текущего узла к новому узлу вызываем метод fix_height для текущего узла и нового узла
// увеличиваем кол-во поворотов на 1 и возвращаем новый узел
nodeAVL *nodeAVL::rotate_left() {
    nodeAVL *p = r;
    r = p->l;
    p->l = this;
    fix_height();
    p->fix_height();
    col_rotations++;
    return p;
}


//Метод балансировки узла
//Вызываем метод balance_factor для текущего узла, если он больше 1 то проверяем правое поддерево на балансировку если меньше 0 то вызываем метод rotate_right.
//Если меньше -1 то проверяем левое поддерево на балансировку если больше 0 то вызываем метод rotate_left.
nodeAVL *nodeAVL::balance() {
    fix_height();
    if (r != nullptr) r = r->balance();
    if (l != nullptr) l = l->balance();
    if (balance_factor() >= 2) {
        if (r->balance_factor() < 0)
            r = r->rotate_right();
        return rotate_left();
    }
    if (balance_factor() <= -2) {
        if (l->balance_factor() > 0)
            l = l->rotate_left();
        return rotate_right();
    }

    return this;
}


//Метод добавления узла
//Если значение узла меньше значения текущего узла то проверяем левое поддерево на пустоту если оно пустое то создаем новый узел и приравниваем его к левому поддереву текущего узла если нет то вызываем метод add для левого поддерева
// если нет то проверяем левое поддерево на пустоту если оно пустое то создаем новый узел и приравниваем его к левому поддереву текущего узла если нет то вызываем метод add для левого поддерева
nodeAVL *nodeAVL::add(Data x) {
    if (x < info) {
        if (l == nullptr) {
            l = new nodeAVL;
            l->info = x;
        } else {
            l = l->add(x);
        }
    } else {
        if (r == nullptr) {
            r = new nodeAVL;
            r->info = x;
        } else {
            r = r->add(x);
        }
    }
    return balance();
}



string nodeAVL::toString() {
    return to_string(info.getNum());
}


//Метод вывода дерева
//Если правое поддерево не пустое то вызываем метод print для правого поддерева, выводим значение текущего узла
// и если левое поддерево не пустое то вызываем метод print для левого поддерева
void nodeAVL::print(string const & rpref, string const & cpref, string const & lpref ) {
    if (r)
        r->print(rpref + "  ", rpref + "\u250C\u2500", rpref + "\u2502 ");
    cout << cpref << info.getNum() << endl;
    if (l)
        l->print( lpref + "\u2502 ", lpref + "\u2514\u2500", lpref + "  ");
}

//Метод вычисления количества поворотов
//Суммируем количество поворотов узла с количеством поворотов левого и правого поддерева если они не пустые
int nodeAVL::getCol_rotations() const {
    return col_rotations + (l != nullptr ? l->getCol_rotations() : 0) + (r != nullptr ? r->getCol_rotations() : 0);
}


//Метод нахождения элемента в дереве
//Если значение узла равно значению искомого узла то возвращаем указатель на текущий узел
// если нет то проверяем левое поддерево на пустоту если оно не пустое то вызываем метод find для левого поддерева
// если нет то проверяем правое поддерево на пустоту если оно не пустое то вызываем метод find для правого поддерева
nodeAVL *nodeAVL::find(int x) {
    if (info.getNum() == x) return this;
    if (x < info.getNum()) {
        if (l == nullptr) return nullptr;
        return l->find(x);
    } else {
        if (r == nullptr) return nullptr;
        return r->find(x);
    }
}
//Метод удаления элемента из дерева
//Если значение узла равно значению искомого узла если у узла нет и правого и левого поддерева то удаляем его и возвращаем nullptr
// если у узла есть только левое поддерево то удаляем его и возвращаем указатель на правое поддерево
// если есть только правое поддерево то удаляем его и возвращаем указатель на левое поддерево
// если есть и правое и левое поддерево то находим минимальный узел в правом поддереве и заменяем его на удаляемый узел
// Если значение узла не равно значению искомого узла то проверяем левое поддерево на пустоту если оно не пустое то вызываем метод remove для левого поддерева
// если нет то проверяем правое поддерево на пустоту если оно не пустое то вызываем метод remove для правого поддерева
nodeAVL *nodeAVL::dell(int x) {
    if (info.getNum() == x) {
        if (l == nullptr && r == nullptr) {
            delete this;
            return nullptr;
        }
        if (l == nullptr) {
            nodeAVL *p = r;
            delete this;
            return p;
        }
        if (r == nullptr) {
            nodeAVL *p = l;
            delete this;
            return p;
        }
        nodeAVL *p = r;
        while (p->l != nullptr) p = p->l;
        info = p->info;
        r = r->dell(p->info.getNum());
    } else {
        if (x < info.getNum()) {
            if (l == nullptr) return this;
            l = l->dell(x);
        } else {
            if (r == nullptr) return this;
            r = r->dell(x);
        }
    }
    return balance();
}
