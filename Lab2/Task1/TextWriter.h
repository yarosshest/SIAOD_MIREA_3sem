//
// Created by yaros on 09.10.2022.
//

#ifndef SIAOD_TEXTWRITER_H
#define SIAOD_TEXTWRITER_H
#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;
class TextWriter {

public:
    static void createFile(string name);
    static void output(string name);
    static bool fileCheck(string name);
    static void addLastRow(string name, string row);
    static string readById(string name, int id);
    static int getVolume(string name);
    static void sort(string name, string outfile);
};


#endif //SIAOD_TEXTWRITER_H
