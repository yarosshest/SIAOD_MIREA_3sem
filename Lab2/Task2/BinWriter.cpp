//
// Created by yaros on 21.09.2022.
//

#include "BinWriter.h"
void BinWriter::writeBin(string name, vector<Auto> autos) {
    ofstream out(name, ios::binary);
    for (Auto i : autos)
        out.write((char*)&i, sizeof(Auto));

    cout << sizeof(Auto) << endl;
    out.close();
}

void BinWriter::readBin(string name, vector<Auto> &autos) {
    ifstream in(name, ios::binary);
    Auto *tmp = new Auto();
    while (in.read((char*)tmp, sizeof(Auto)))
        autos.push_back(*tmp);
    in.close();
}

void BinWriter::outputBin(string name) {
    ifstream in(name, ios::binary);
    Auto *tmp = new Auto();
    while (in.read((char*)tmp, sizeof(Auto)))
        cout << tmp->toString() << endl;
    in.close();
}

Auto BinWriter::readAuto(string name, int index) {
    ifstream in(name, ios::binary);
    Auto tmp;
    in.seekg(index * sizeof(Auto));
    in.read((char*)&tmp, sizeof(Auto));
    in.close();
    return tmp;
}

void BinWriter::dellAuto(string name, int index) {
    vector<Auto> autos;
    readBin(name, autos);
    autos.erase(autos.begin() + index);
    writeBin(name, autos);
}

void BinWriter::writeAuto(string name, Auto au, int index) {
    ofstream out(name, ios::binary);
    out.seekp(index);
    out.write((char*)&au, sizeof(Auto));
    out.close();
}
