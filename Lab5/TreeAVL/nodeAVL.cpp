//
// Created by yaros on 26.10.2022.
//

#include "nodeAVL.h"

int nodeAVL::balance_factor() {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    return hr - hl;
}

void nodeAVL::fix_height() {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    height = (hl > hr ? hl : hr) + 1;
}

nodeAVL *nodeAVL::rotate_right() {
    nodeAVL *q = l;
    l = q->r;
    q->r = this;
    fix_height();
    q->fix_height();
    return q;
}

nodeAVL *nodeAVL::rotate_left() {
    nodeAVL *p = r;
    r = p->l;
    p->l = this;
    fix_height();
    p->fix_height();
    return p;
}

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

nodeAVL *nodeAVL::add(char x) {
    if (info == NULL) {
        info = x;
        return this;
    }
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

string toString(char &value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

void nodeAVL::print(string &resul) {
    if (l != nullptr) {
        resul.append(toString(info));
        resul.append("->");
        resul.append(toString(l->info));
        resul.append(";");
        l->print(resul);
    }
    if (r != nullptr) {
        resul.append(toString(info));
        resul.append("->");
        resul.append(toString(r->info));
        resul.append(";");
        r->print(resul);
    }

}



