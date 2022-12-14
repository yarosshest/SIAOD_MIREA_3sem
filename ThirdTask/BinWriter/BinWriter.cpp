//
// Created by yaros on 21.09.2022.
//

#include "BinWriter.h"
void BinWriter::writeBin(string name){
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



void BinWriter::outputBin() const {
    if (fileCheck(nameBin)) {
        ifstream in(nameBin, ios::binary);
        Auto *tmp = new Auto();
        while (in.read((char *) tmp, sizeof(Auto)))
            cout << tmp->out() << endl;
        in.close();
    }
}

Auto* BinWriter::readAuto( int index) {

    if (fileCheck(nameBin)) {
        uintmax_t n = filesystem::file_size(nameBin);
        if((index+1) * sizeof(Auto) <= n) {
            ifstream in(nameBin, ios::binary);
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



void BinWriter::dellAuto(int id) {
    int ind = getIndexById(id);
    if (ind < 0){
        cout << "No such id" << endl;
        return;
    }else{
        if (fileCheck(nameBin)) {
            fstream out(nameBin, ios::binary | ios::out | ios::in);
            uintmax_t n = filesystem::file_size(nameBin);
            Auto *tmp = new Auto();
            out.seekg(n - sizeof(Auto), ios::beg);
            out.read((char *) tmp, sizeof(Auto));
            out.close();
            writeAuto( *tmp, ind);
            filesystem::resize_file(nameBin, n - sizeof(Auto));
        }
    }
}

void BinWriter::writeAuto(Auto au, int index) {
    if (fileCheck(nameBin)) {
        fstream out(nameBin, ios::binary | ios::in | ios::out);
        out.seekp(index * sizeof(Auto), ios::beg);
        out.write((char *) &au, sizeof(Auto));
        out.close();
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

int BinWriter::getIndexById(int id) {
    if (fileCheck(nameBin)) {
        ifstream in(nameBin, ios::binary);
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

void BinWriter::readBin(vector<Auto> &autos) {
    if (fileCheck(nameBin)) {
        ifstream in(nameBin, ios::binary);
        Auto *tmp = new Auto();
        while (in.read((char *) tmp, sizeof(Auto)))
            autos.push_back(*tmp);
        in.close();
    }
}

int BinWriter::GetSize() const {
    if (fileCheck(nameBin)) {
        ifstream in(nameBin, ios::binary);
        in.seekg(0, ios::end);
        int size = in.tellg();
        in.close();
        return size / sizeof(Auto);
    }
    return 0;
}

BinWriter::BinWriter(string name, string str) {
    nameBin = name;
    writeBin(str);
}

int BinWriter::addAuto(Auto au) {
    if (fileCheck(nameBin)) {
        fstream out(nameBin, ios::binary | ios::out | ios::app);
        out.write((char *) &au, sizeof(Auto));
        out.close();
        return (out.tellg() / sizeof(Auto)) - 1;
    }
    return -1;
}


