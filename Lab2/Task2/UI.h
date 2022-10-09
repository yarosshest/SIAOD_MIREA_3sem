//
// Created by yaros on 30.09.2022.
//

#ifndef SIAOD_UI_H
#define SIAOD_UI_H
#include <string>
#include <iostream>
#include "BinWriter.h"
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
    BinWriter bw = BinWriter();
    bool isExit = false;
    string menu = "1. Writing to a binary file from a text file\n"
                  "2. Writing from a binary file to a text file\n"
                  "3. Output all binary records\n"
                  "4. Reading from a binary file by index\n"
                  "5. Deleting from a binary file by index\n"
                  "6. Change the inspection dates of a vehicle with a given number to a new date\n"
                  "7. Display a list of vehicles of the same model inspected on a given date\n";
public:
    void start();

};


#endif //SIAOD_UI_H
