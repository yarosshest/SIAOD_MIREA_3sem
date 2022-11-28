//
// Created by yaros on 26.10.2022.
//

#include "node.h"

void node::print(string &resul) {
    if (l != nullptr) {
        resul.append(to_string(key));
        resul.append("->");
        resul.append(to_string(l->key));
        resul.append(";");
        l->print(resul);
    }
    if (r != nullptr) {
        resul.append(to_string(key));
        resul.append("->");
        resul.append(to_string(r->key));
        resul.append(";");
        r->print(resul);
    }

}

node::node(vector<Data> &keys) {
    if (keys.size() == 1) {
        key = keys[0].getNum();
        ptr = keys[0].getShift();
    }
    else if (keys.size() == 2) {
        key = keys[1].getNum();
        ptr = keys[1].getShift();
        auto nlB = keys.begin();
        auto nlE = keys.end()-1;
        vector<Data> nl(nlB, nlE);
        vector<Data> cop;
        copy(nl.begin(), nl.end(), back_inserter(cop));
        l = new node(cop);
    }
    else {
        int n = (keys.size() /2) ;
        auto nlB = keys.begin();
        auto nlE = keys.begin()+n;
        vector<Data> left(nlB, nlE);
        auto nrB = keys.begin()+n+1;
        auto nrE = keys.end();
        vector<Data> right(nrB, nrE);

        key = keys[n].getNum();
        ptr = keys[n].getShift();

        vector<Data> leftC;
        vector<Data> rightC;

        copy(left.begin(), left.end(), back_inserter(leftC));
        copy(right.begin(), right.end(), back_inserter(rightC));
        l = new node(leftC);
        r = new node(rightC);
    }
}

int node::height(int x) {
    if (key == x) {
        return 1;
    }
    else if (x < key) {
        return 1 + l->height(x);
    }
    else {
        return 1 + r->height(x);
    }
}

int node::countChild() {
    int count = 0;
    if (l != nullptr) {
        count = count + 1 + l->countChild();
    }
    if (r != nullptr) {
        count = count + 1 + r->countChild();
    }
    return count;
}

void node::printLeft(string const & rpref, string const & cpref, string const & lpref ) {
    if (r)
        r->printLeft(rpref + "  ", rpref + "\u250C\u2500", rpref + "\u2502 ");
    cout << cpref << key << endl;
    if (l)
        l->printLeft( lpref + "\u2502 ", lpref + "\u2514\u2500", lpref + "  ");
}

void node::printhight(const string &prefix, bool root, bool last) {
    cout << prefix << (root ? "" : (last ? "\u2514\u2500" : "\u251C\u2500")) << key << endl;
    if (!l && !r)
        return;
    vector<node*> v;
    if (l)
        v.push_back(l);
    if (r)
        v.push_back(r);
    for (size_t i = 0; i < v.size(); ++i)
        v[i]->printhight( prefix + (root ? "" : (last ? "  " : "\u2502 ")), false, i + 1 >= v.size());
}

Data node::findByKey(int x) {
    if (x == key) {
        return *BinWriter::readData("bin.bin", ptr);
    }
    else if (x < key) {
        return l->findByKey(x);
    }
    else {
        return r->findByKey(x);
    }
}



