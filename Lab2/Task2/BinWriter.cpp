//
// Created by yaros on 21.09.2022.
//

#include "BinWriter.h"
void BinWriter::writeBin(string name, string nameBin){
    ifstream file (name);
    ofstream fileBin(nameBin, ios::binary| ios::out | ios::trunc);
    if (!file)
    {
        cout << "File doesn't exist\n";
        file.close();
        fileBin.close();
    }
    else
    {
        string line;
        while (getline(file, line)) {
            vector<char *> data = vector<char *>();
            char *str = const_cast<char *>(line.c_str());

            char *tmp_char = strtok(str, ";");

            while (tmp_char != NULL && *(tmp_char) != '\r') {
                data.push_back(tmp_char);
                tmp_char = strtok(NULL, ";");
            }
            Auto au = Auto(data);
            fileBin.write((char *) &au, sizeof(au));
        }
        file.close();
        fileBin.close();
    }
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
        cout << tmp->out() << endl;
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
//    writeBin(name, autos);
}

void BinWriter::writeAuto(string name, Auto au, int index) {
    fstream out(name, ios::binary|ios::in|ios::out);
    out.seekp(index*sizeof(Auto), ios::beg);
    out.write((char*)&au, sizeof(Auto));
    out.close();
}

void BinWriter::rep(string date,string reg ,string num, string buk, string name)
{
    vector<Auto> result = vector<Auto>();
    readBin(name, result);
    int index = 0;
    for(Auto i : result)
    {
        if(i.region == reg && i.num == num && i.characters == buk)
        {
            i.date = date;
            writeAuto(name, i, index);
        }
        index++;
    }
}

void BinWriter::showMod(string date,string mod ,string name)
{
    vector<Auto> result = vector<Auto>();
    readBin(name, result);
    for(Auto i : result)
        if(i.date == date && i.model == mod )
            cout << i.toString() << endl;
}

void BinWriter::writeSource(string nameBin, string src) {
    ifstream file(nameBin,  ios::binary);
    ofstream fileSrc(src, ios::out|ios::trunc);
    if (!file)
    {
        cout << "File doesn't exist\n";
        file.close();
        fileSrc.close();
    }
    else
    {
        Auto *tmp = new Auto();
        while (file.read((char*)tmp, sizeof(Auto)))
            fileSrc << tmp->toString() << endl;

        file.close();
        fileSrc.close();
    }
}
