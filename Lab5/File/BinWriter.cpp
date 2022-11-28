//
// Created by yaros on 21.09.2022.
//

#include "BinWriter.h"

void BinWriter::writeBin(string name, string nameBin){
    if (fileCheck(name))
    {
        ifstream file (name, ios::in);
        ofstream fileBin(nameBin, ios::binary| ios::out | ios::trunc);

        string line;
        while (getline(file, line)) {
            vector<char *> data = vector<char *>();
            char *str = const_cast<char *>(line.c_str());

            char *tmp_char = strtok(str, ";");

            while (tmp_char != NULL && *(tmp_char) != '\r') {
                data.push_back(tmp_char);
                tmp_char = strtok(NULL, ";");
            }
            Data au = Data(data);
            fileBin.write((char *) &au, sizeof(au));
        }
        file.close();
        fileBin.close();
    }
}


Data* BinWriter::readData(string name, int index) {

    if (fileCheck(name)) {
        uintmax_t n = filesystem::file_size(name);
        if((index+1) * sizeof(Data) < n) {
            ifstream in(name, ios::binary);
            in.seekg(index * sizeof(Data));
            Data *tmp = new Data();
            in.read((char *) tmp, sizeof(Data));
            in.close();
            return tmp;
        }else{
            cout << "Index out of range" << endl;
            return new Data();
        }
    }
    else
        return new Data();
}



void BinWriter::dellData(string name, int id) {
    int ind = getIndexById(name, id);
    if (ind < 0){
        cout << "No such id" << endl;
        return;
    }else{
        if (fileCheck(name)) {
            fstream out(name, ios::binary | ios::out | ios::in);
            uintmax_t n = filesystem::file_size(name);
            Data *tmp = new Data();
            out.seekg(n - sizeof(Data), ios::beg);
            out.read((char *) tmp, sizeof(Data));
            out.close();
            writeData(name, *tmp, ind);
            filesystem::resize_file(name, n - sizeof(Data));
        }
    }
}

void BinWriter::writeData(string name, Data au, int index) {
    if (fileCheck(name)) {
        fstream out(name, ios::binary | ios::in | ios::out);
        out.seekp(index * sizeof(Data), ios::beg);
        out.write((char *) &au, sizeof(Data));
        out.close();
    }
}

bool BinWriter::fileCheck(string name)  {
    ifstream fileSrc(name);
    if (!fileSrc)
    {
        cout << "File doesn't exist\n";
        fileSrc.close();
        return false;
    }else{
        fileSrc.close();
        return true;
    }
}

int BinWriter::getIndexById(string name, int id) {
    if (fileCheck(name)) {
        ifstream in(name, ios::binary);
        Data *tmp = new Data();
        int index = 0;
        while (in.read((char *) tmp, sizeof(Data))) {
            if (tmp->getNum() == id)
                return index;
            index++;
        }
        in.close();
    }
    return -1;
}

void BinWriter::readBin(string name, vector<Data> &Datas) {
    if (fileCheck(name)) {
        ifstream in(name, ios::binary);
        Data *tmp = new Data();
        while (in.read((char *) tmp, sizeof(Data)))
            Datas.push_back(*tmp);
        in.close();
    }
}

Data BinWriter::findByKey(string name, int num) {
    Data res = Data();
    if (fileCheck(name)) {
        ifstream in(name, ios::binary);
        Data *tmp = new Data();
        while (in.read((char *) tmp, sizeof(Data))) {
            if (tmp->getNum() == num)
                return *tmp;
        }
        in.close();
    }
    return res;
}

int BinWriter::addData(string name, Data au) {
    if (fileCheck(name)) {
        ofstream out(name, ios::binary | ios::app);
        out.write((char *) &au, sizeof(au));
        out.close();
        uintmax_t n = filesystem::file_size(name);
        return (n / sizeof(Data)) - 1;
    }
    return -1;
}


