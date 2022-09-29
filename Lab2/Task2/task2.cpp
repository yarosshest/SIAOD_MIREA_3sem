//
// Created by yaros on 21.09.2022.
//
#include "ReaderSource.h"
void replace(string reg ,string num, string buk, vector<Auto> autos, string name)
{
    vector<Auto> result = vector<Auto>();

    ifstream in(name, ios::binary);
    Auto *tmp = new Auto();
    while (in.read((char*)tmp, sizeof(Auto)))
        if

    for (Auto i : autos)
        if (i.num == num && i.region == reg && i.characters == buk)
            i.}

    ReaderSource readerSource = ReaderSource();
    readerSource.writeSource(name, result);
}