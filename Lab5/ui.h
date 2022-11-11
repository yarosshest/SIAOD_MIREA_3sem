//
// Created by yaros on 11.11.2022.
//

#ifndef SIAOD_UI_H
#define SIAOD_UI_H

#include "File/BinWriter.h"
#include "Tree/Tree.h"
#include "Data.h"
#include "TreeAVL/TreeAVL.h"
#include <chrono>
class ui {
    string file_10 = R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab5\test_10.txt)";
    string file_1000 = R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab5\test_1000.txt)";
    string file_10000 = R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab5\test_10000.txt)";
    string file_50000 = R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab5\test_50000.txt)";
    string file_100000 = R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab5\test_100000.txt)";
public:
    void timeTest();
    void start();
    string chooseFile();
    void binMenu();
    void treeMenu();
    void treeAVLMenu();
};


#endif //SIAOD_UI_H
