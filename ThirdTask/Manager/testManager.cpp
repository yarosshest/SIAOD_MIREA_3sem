//
// Created by yaros on 14.12.2022.
//

#include "Manager.h"

int testManager(){
    Manager m = Manager(R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\ThirdTask\bin)", R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\ThirdTask\txt.txt)");
    cout << "====================" << endl;
    m.Output();
    m.pasteFile();
    m.Output();
    cout << "====================" << endl;
    m.Remove("5");
    m.Output();
    cout << "====================" << endl;
    Auto a = m.Search("4");
    cout << a.out() << endl;
    cout << "====================" << endl;
    cout << "Big test" << endl;
    cout << "====================" << endl;
    return 0;
}

int testBigFile(){
    Manager m = Manager(R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\ThirdTask\bin2)", R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\ThirdTask\test_100000.txt)");
    m.pasteFile();
    cout << "====================" << endl;
    cout << "Start of file" << endl;
    cout << "Table time";
    char* id = "1996WIt";
    auto start = chrono::steady_clock::now();
    Auto a = m.Search(id);
    auto end = chrono::steady_clock::now();
    cout << "Time of search: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "File time";
    start = chrono::steady_clock::now();
    int index = m.SearchFile(id);
    end = chrono::steady_clock::now();
    cout << "Time of search: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "====================" << endl;
    cout << "Midle of file" << endl;
    cout << "Table time";
    id = "3211mQb";
    start = chrono::steady_clock::now();
    a = m.Search(id);
    end = chrono::steady_clock::now();
    cout << "Time of search: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "File time";
    start = chrono::steady_clock::now();
    index = m.SearchFile(id);
    end = chrono::steady_clock::now();
    cout << "Time of search: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "====================" << endl;
    cout << "End of file" << endl;
    cout << "Table time";
    id = "7228nyy";
    start = chrono::steady_clock::now();
    a = m.Search(id);
    end = chrono::steady_clock::now();
    cout << "Time of search: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "File time";
    start = chrono::steady_clock::now();
    index = m.SearchFile(id);
    end = chrono::steady_clock::now();
    cout << "Time of search: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    return 0;
};