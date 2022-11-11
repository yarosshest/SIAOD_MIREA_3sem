//
// Created by yaros on 26.10.2022.
//

#include "nodeAVL.h"

int nodeAVL::balance_factor() const {
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
    col_rotations++;
    return q;
}

nodeAVL *nodeAVL::rotate_left() {
    nodeAVL *p = r;
    r = p->l;
    p->l = this;
    fix_height();
    p->fix_height();
    col_rotations++;
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

nodeAVL *nodeAVL::add(Data x) {
    if (info == Data()) {
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

string nodeAVL::toString() {
    return info.num;
}

void nodeAVL::print(string const & rpref, string const & cpref, string const & lpref ) {
    if (r)
        r->print(rpref + "  ", rpref + "\u250C\u2500", rpref + "\u2502 ");
    cout << cpref << info.num << endl;
    if (l)
        l->print( lpref + "\u2502 ", lpref + "\u2514\u2500", lpref + "  ");
}

int nodeAVL::getCol_rotations() const {
    return col_rotations + (l != nullptr ? l->getCol_rotations() : 0) + (r != nullptr ? r->getCol_rotations() : 0);
}

nodeAVL *nodeAVL::find(string x) {
    if (info.num == x) return this;
    if (x < info.num) {
        if (l == nullptr) return nullptr;
        return l->find(x);
    } else {
        if (r == nullptr) return nullptr;
        return r->find(x);
    }
}

nodeAVL *nodeAVL::dell(string x) {
    if (info.num == x) {
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
        r = r->dell(p->info.num);
    } else {
        if (x < info.num) {
            if (l == nullptr) return this;
            l = l->dell(x);
        } else {
            if (r == nullptr) return this;
            r = r->dell(x);
        }
    }
    return balance();
}
