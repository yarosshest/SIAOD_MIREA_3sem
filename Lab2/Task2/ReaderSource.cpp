//
// Created by yaros on 21.09.2022.
//

#include "ReaderSource.h"
vector<Auto> ReaderSource::readSource(string name)
{
    vector<Auto> result = vector<Auto>();
    ifstream file (name);
    if (!file)
    {
        cout << "File doesn't exist\n";
        return result;
    }
    else
    {
        cout << "File open\n";
        string line;
        while ( getline (file, line) )
        {
            vector<char*> data = vector<char*>();
            char *str = const_cast<char *>(line.c_str());

            char *tmp_char = strtok(str, ";");

            while (tmp_char != NULL)
            {
                data.push_back(tmp_char);
                tmp_char = strtok(NULL, ";");
            }
            result.emplace_back(data);
        }
        file.close();
        return result;
    }
}

void ReaderSource::writeSource(string name, vector<Auto> autos) {
    ofstream file(name);
    for (Auto i : autos)
        file << i.toString() << endl;
    file.close();
}
