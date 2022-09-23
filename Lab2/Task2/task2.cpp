//
// Created by yaros on 21.09.2022.
//
#include "ReaderSource.h"
void replace(string reg ,string num, string buk, vector<Auto> autos, string name)
{
    vector<Auto> result = vector<Auto>();
    for (Auto i : autos)
        if (i.num == num)
            result.push_back(i);

    ReaderSource readerSource = ReaderSource();
    readerSource.writeSource(name, result);
}