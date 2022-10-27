//
// Created by yaros on 26.10.2022.
//

#include "node.h"
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

node::node(vector<char> &keys) {
    if (keys.size() == 1) {
        info = keys[0];
    }
    else if (keys.size() == 2) {
        info = keys[1];
        vector<char>::const_iterator nlB = keys.begin();
        vector<char>::const_iterator nlE = keys.end()-1;
        vector<char> nl(nlB, nlE);
        vector<char> cop;
        copy(nl.begin(), nl.end(), back_inserter(cop));
        l = new node(cop);
    }
    else {
        int n = (keys.size() /2) ;
        vector<char>::const_iterator nlB = keys.begin();
        vector<char>::const_iterator nlE = keys.begin()+n;
        vector<char> left(nlB, nlE);
        vector<char>::const_iterator nrB = keys.begin()+n+1;
        vector<char>::const_iterator nrE = keys.end();
        vector<char> right(nrB, nrE);
        info = keys[n];

        vector<char> leftC;
        vector<char> rightC;

        copy(left.begin(), left.end(), back_inserter(leftC));
        copy(right.begin(), right.end(), back_inserter(rightC));
        l = new node(leftC);
        r = new node(rightC);
    }
}

int node::height(char x) {
    if (info == x) {
        return 1;
    }
    else if (x < info) {
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
    cout << cpref << info << endl;
    if (l)
        l->printLeft( lpref + "\u2502 ", lpref + "\u2514\u2500", lpref + "  ");
}

void node::printhight(const string &prefix, bool root, bool last) {
    cout << prefix << (root ? "" : (last ? "\u2514\u2500" : "\u251C\u2500")) << info << endl;
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



