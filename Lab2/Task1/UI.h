//
// Created by yaros on 30.09.2022.
//

#ifndef SIAOD_UI_H
#define SIAOD_UI_H
#include <string>
#include <iostream>
#include "TextWriter.h"
using namespace std;
class UI {
private:
    string name;
    string date;
    string buk;
    string reg;
    string num;
    string mod;
    string nameBin;
    int task;
    int index;
    bool isExit = false;
    string menu = "1. Creating a text file\n"
                  "2. Text file output\n"
                  "3. Adding a new line to the end of the file\n"
                  "4. Reading from a file by index\n"
                  "5. Determine the number of numbers in the file\n";
public:
    void start();

};


#endif //SIAOD_UI_H
