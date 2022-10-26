//
// Created by yaros on 26.10.2022.
//

#include "node.h"

int node::balance_factor() {
    int hl = 0, hr = 0;
    if (l != nullptr) hl = l->height;
    if (r != nullptr) hr = r->height;
    return hr - hl;
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

node *node::add(char x) {
    if (info == NULL) {
        info = x;
        return this;
    }
    if (x < info) {
        if (l == nullptr) {
            l = new node;
            l->info = x;
        } else {
            l = l->add(x);
        }
    } else {
        if (r == nullptr) {
            r = new node;
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

void node::print(string &resul) {
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



