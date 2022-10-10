//
// Created by yaros on 09.10.2022.
//

#include "TextWriter.h"

void TextWriter::createFile(string name) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,10);

    ofstream file;
    file.open(name, ios::out | ios::trunc);

    int x = dist(gen);
    for (unsigned i = 0; i < x; i++) {
        int y = dist(gen);
        for (unsigned j = 0; j < y ; j++) {
            file << dist(gen) << " ";
        }
        file << endl;
    }
    file.close();
}



void TextWriter::output(string name) {
    if (fileCheck(name)) {
        ifstream file(name, ios::in);
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
}

bool TextWriter::fileCheck(string name) {
    ifstream fileSrc(name);
    if (!fileSrc){
        cout << "File doesn't exist\n";
        fileSrc.close();
        return false;
    }else{
        fileSrc.close();
        return true;
    }
}

void TextWriter::addLastRow(string name, string row) {
    if (fileCheck(name)) {
        ofstream file(name, ios::app);
        file << row << endl;
        file.close();
    }
}

string TextWriter::readById(string name, int id) {
    if (fileCheck(name)) {
        ifstream file(name, ios::in);
        string line;
        int index = 0;
        while (getline(file, line)) {
            char *str = const_cast<char *>(line.c_str());
            char *tmp_char = strtok(str, " ");
            while (tmp_char != nullptr && *(tmp_char) != '\r') {
                if (index == id)
                    return tmp_char;
                index++;
                tmp_char = strtok(nullptr, " ");
            }
        }
        file.close();
    }
    return "index out of range";
}

int TextWriter::getVolume(string name) {
    if (fileCheck(name)) {
        ifstream file(name, ios::in);
        string line;
        int index = 0;
        while (getline(file, line)) {
            char *str = const_cast<char *>(line.c_str());
            char *tmp_char = strtok(str, " ");
            while (tmp_char != nullptr && *(tmp_char) != '\r') {
                index++;
                tmp_char = strtok(nullptr, " ");
            }
        }
        file.close();
        return index;
    }
    return 0;
}

void TextWriter::sort(string name, string outfile) {
    int uneven = 0;
    int even = 0;
    int val;
    string sEven = "";
    string sUneven = "";

    if (fileCheck(name)) {
        ifstream file(name, ios::in);
        string line;
        int index = 0;
        while (getline(file, line)) {
            char *str = const_cast<char *>(line.c_str());
            char *tmp_char = strtok(str, " ");
            while (tmp_char != nullptr && *(tmp_char) != '\r') {
                val = atoi(tmp_char);
                if (val % 2 == 0) {
                    even++;
                    sEven += tmp_char;
                    sEven += " ";
                } else {
                    uneven++;
                    sUneven += tmp_char;
                    sUneven += " ";
                }
                tmp_char = strtok(nullptr, " ");
            }
        }
        file.close();
    }
    ofstream file;
    file.open(outfile, ios::out | ios::trunc);
    file << uneven  <<" "+ sUneven << endl;
    file << even  <<" "+ sEven << endl;
}


