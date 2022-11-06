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
            Auto au = Auto(data);
            fileBin.write((char *) &au, sizeof(au));
        }
        file.close();
        fileBin.close();
    }
}



void BinWriter::outputBin(string name) {
    if (fileCheck(name)) {
        ifstream in(name, ios::binary);
        Auto *tmp = new Auto();
        while (in.read((char *) tmp, sizeof(Auto)))
            cout << tmp->out() << endl;
        in.close();
    }
}

Auto* BinWriter::readAuto(string name, int index) {

    if (fileCheck(name)) {
        uintmax_t n = filesystem::file_size(name);
        if((index+1) * sizeof(Auto) < n) {
            ifstream in(name, ios::binary);
            in.seekg(index * sizeof(Auto));
            Auto *tmp = new Auto();
            in.read((char *) tmp, sizeof(Auto));
            in.close();
            return tmp;
        }else{
            cout << "Index out of range" << endl;
            return new Auto();
        }
    }
    else
        return new Auto();
}



void BinWriter::dellAuto(string name, int id) {
    int ind = getIndexById(name, id);
    if (ind < 0){
        cout << "No such id" << endl;
        return;
    }else{
        if (fileCheck(name)) {
            fstream out(name, ios::binary | ios::out | ios::in);
            uintmax_t n = filesystem::file_size(name);
            Auto *tmp = new Auto();
            out.seekg(n - sizeof(Auto), ios::beg);
            out.read((char *) tmp, sizeof(Auto));
            out.close();
            writeAuto(name, *tmp, ind);
            filesystem::resize_file(name, n - sizeof(Auto));
        }
    }
}

void BinWriter::writeAuto(string name, Auto au, int index) {
    if (fileCheck(name)) {
        fstream out(name, ios::binary | ios::in | ios::out);
        out.seekp(index * sizeof(Auto), ios::beg);
        out.write((char *) &au, sizeof(Auto));
        out.close();
    }
}

void BinWriter::rep(string date,string reg ,string num, string buk, string name)
{
    if (fileCheck(name)) {
        vector<Auto> result = vector<Auto>();
        readBin(name, result);
        int index = 0;
        for (Auto i: result) {
            if (i.region == reg && i.num == num && i.characters == buk) {
                i.date = date;
                writeAuto(name, i, index);
            }
            index++;
        }
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
    if (fileCheck(nameBin)) {
        ifstream file(nameBin, ios::binary);
        ofstream fileSrc(src, ios::out | ios::trunc);
        if (!file) {
            cout << "File doesn't exist\n";
            file.close();
            fileSrc.close();
        } else {
            Auto *tmp = new Auto();
            while (file.read((char *) tmp, sizeof(Auto)))
                fileSrc << tmp->toString() << endl;

            file.close();
            fileSrc.close();
        }
    }
}

bool BinWriter::fileCheck(string name) const {
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
        Auto *tmp = new Auto();
        int index = 0;
        while (in.read((char *) tmp, sizeof(Auto))) {
            if (stoi(tmp->id) == id)
                return index;
            index++;
        }
        in.close();
    }
    return -1;
}

void BinWriter::readBin(string name, vector<Auto> &autos) {
    if (fileCheck(name)) {
        ifstream in(name, ios::binary);
        Auto *tmp = new Auto();
        while (in.read((char *) tmp, sizeof(Auto)))
            autos.push_back(*tmp);
        in.close();
    }
}


