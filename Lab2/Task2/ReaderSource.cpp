//
// Created by yaros on 21.09.2022.
//

#include "ReaderSource.h"
vector<Auto> ReaderSource::readSource()
{
    vector<Auto> result = vector<Auto>();
    ifstream file ("Source.txt");
    if (!file)
    {
        cout << "Файл не найден\n";
        return result;
    }
    else
    {
        cout << "Файл открыт\n";
        string line;
        while(true) {
            getline(file, line);
            if(!file.eof())
                cout << line << endl;
            else break;
        }
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
        getline (file, line);
        file.close();
        return result;
    }
}
