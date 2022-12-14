//
// Created by yaros on 14.12.2022.
//

#include "Manager.h"

int testManager(){
    Manager m = Manager(R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\ThirdTask\txt.txt)", "test.bin");
    cout << "====================" << endl;
    m.Output();
    m.Remove("5");
    m.Output();
    cout << "====================" << endl;
    m.SaveEntry(5);
    m.Output();
    cout << "====================" << endl;
    Auto a = m.Search("5");
    cout << a.out() << endl;
}