//
// Created by yaros on 21.09.2022.
//

#include "ReaderSource.h"
vector<Auto> ReaderSource::readSource(const string& path) {
    string line;
    vector<Auto> result = vector<Auto>();
    ifstream file;
    file.open(path);
    if (!file)
    {
        cout << "Файл не найден\n";
        return result;
    }
    else
    {
        cout << "Файл открыт\n";

        return result;
    }
}
