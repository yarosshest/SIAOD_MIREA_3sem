//
// Created by yaros on 26.10.2022.
//

#include "node.h"

int node::balance_factor() {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    return hl - hr;
}

void node::fix_height() {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    height = (hl > hr ? hl : hr) + 1;
}

node *node::rotate_right() {
    node *q = l;
    l = q->r;
    q->r = this;
    fix_height();
    q->fix_height();
    return q;
}

node *node::rotate_left() {
    node *p = r;
    r = p->l;
    p->l = this;
    fix_height();
    p->fix_height();
    return p;
}

node *node::balance() {
    fix_height();
    if (balance_factor() == 2) {
        if (l->balance_factor() < 0)
            l = l->rotate_left();
        return rotate_right();
    }
    if (balance_factor() == -2) {
        if (r->balance_factor() > 0)
            r = r->rotate_right();
        return rotate_left();
    }
    return this;
}

node *node::add(char x) {
    if (info == NULL) {
        info = x;
        return this;
    }
    if (x < info) {
        if (l == nullptr) {
            l = new node();
        }
        l = l->add(x);
    } else {
        if (r == nullptr) {
            r = new node();
        }
        r = r->add(x);
    }
    return balance();
}

void node::print(const string &rpref, const string &cpref, const string &lpref) {
    if (this == nullptr) return;
    if (r)
        r->print(rpref + "  ", rpref + "\u250C\u2500", rpref + "\u2502 ");
    std::cout << cpref << info << std::endl;
    if (l)
        l->print(lpref + "\u2502 ", lpref + "\u2514\u2500", lpref + "  ");
}



