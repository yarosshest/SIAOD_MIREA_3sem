//
// Created by yaros on 11.11.2022.
//

#include "ui.h"

void ui::timeTest() {
    string file = R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab5\test_50000.txt)";
    BinWriter binWriter;
    binWriter.writeBin(file, "bin.bin");
    Tree tree(file);
    TreeAVL tree_avl(file);


    cout << "in beginning file" << endl;
//    int el_begin = 4104239; // for 10
//    string el_begin= "9169538"; // for 1000
//    int el_begin= 5792242; // for 10000
    int el_begin= 9757871; // for 50000
//    string el_begin= "1620461"; // for 100000

    cout<< "Binary file" << endl;
    auto start = chrono::steady_clock::now();
    binWriter.findByKey("bin.bin",el_begin);
    auto end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    cout<< "Binary tree" << endl;
    start = chrono::steady_clock::now();
    tree.findByKey(el_begin);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    cout << "AVL tree" << endl;
    start = chrono::steady_clock::now();
    tree_avl.find(el_begin);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    cout << "-------------------------" << endl;
    cout << "in middle file" << endl;
//    int el_middle = 7749565; // for 10
//    string el_middle = "4371153"; // for 1000
//    int el_middle = 1050535; // for 10000
    int el_middle = 3995014; // for 50000
//    string el_middle = "4966234"; // for 100000

    cout<< "Binary file" << endl;
    start = chrono::steady_clock::now();
    binWriter.findByKey("bin.bin",el_middle);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    cout<< "Binary tree" << endl;
    start = chrono::steady_clock::now();
    tree.findByKey(el_middle);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    cout << "AVL tree" << endl;
    start = chrono::steady_clock::now();
    tree_avl.find(el_middle);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()  << endl;

    cout << "-------------------------" << endl;
    cout << "in end file" << endl;
//    int el_end = 7425717; // for 10
//    string el_end = "9096521"; // for 1000
//    int el_end = 4937097; // for 10000
    int el_end = 2623654; // for 50000
//    string el_end = "9582059"; // for 100000

    cout<< "Binary file" << endl;
    start = chrono::steady_clock::now();
    binWriter.findByKey("bin.bin",el_end);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;

    cout<< "Binary tree" << endl;
    start = chrono::steady_clock::now();
    tree.findByKey(el_end);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()  << endl;


    cout << "AVL tree" << endl;
    start = chrono::steady_clock::now();
    tree_avl.find(el_end);
    end = chrono::steady_clock::now();
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count()  << endl;
}

void ui::start() {
    bool exit = false;
    string type;
    while (!exit){
        cout << "choose type" << endl;
        cout << "1. Binary file\n"
                "2. Binary tree\n"
                "3. AVL tree\n" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                binMenu();
                exit = true;
                break;
            case 2:
                treeMenu();
                exit = true;
                break;
            case 3:
                treeAVLMenu();
                exit = true;
                break;
            default:
                cout << "wrong choose" << endl;
                return;
        }
    }
}

void ui::binMenu() {
    string file = chooseFile();
    BinWriter binWriter;
    binWriter.writeBin(file, "file.bin");
    bool exit = false;
    while (!exit){
        cout << "choose action" << endl;
        cout << "1. Find by index\n"
                "2. Add element\n"
                "3. Exit" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "enter index" << endl;
                int index;
                cin >> index;
                cout << binWriter.readData("file.bin",index)->print() << endl;
                break;
            case 2:
                break;
            case 3:
                exit = true;
                break;
            default:
                cout << "wrong choose" << endl;
                return;
        }
    }
}

string ui::chooseFile() {
    bool exit = false;
    string file;
    while (!exit){
        cout << "choose file" << endl;
        cout << "1. 10\n"
                "2. 1000\n"
                "3. 10000\n"
                "4. 50000\n"
                "5. 100000\n" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                file = file_10;
                exit = true;
                break;
            case 2:
                file = file_1000;
                exit = true;
                break;
            case 3:
                file = file_10000;
                exit = true;
                break;
            case 4:
                file = file_50000;
                exit = true;
                break;
            case 5:
                file = file_100000;
                exit = true;
                break;
            default:
                cout << "wrong choose" << endl;
        }
    }
    return file;
}

void ui::treeMenu() {
    string file = chooseFile();
    Tree tree = Tree(file);
    bool exit = false;
    string key;
    Data data;
    while (!exit){
        cout << "choose action" << endl;
        cout << "1. Find by key\n"
                "2. Add element\n"
                "3. Dell element\n"
                "4. print tree\n"
                "5. Exit" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "enter key" << endl;
                cin >> key;
                cout << tree.findByKey(stoi(key)).print() << endl;
                break;
            case 2:
                cout << "enter uiser" << endl;
                data = Data(true);
                tree.add(data);
                break;
            case 3:
                cout << "enter key" << endl;
                cin >> key;
                tree.dell(key);
                break;
            case 4:
                tree.printLeft();
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "wrong choose" << endl;
                return;
        }
    }
}

void ui::treeAVLMenu() {
    string file = chooseFile();
    TreeAVL tree = TreeAVL(file);
    bool exit = false;
    string key;
    Data data;
    while (!exit){
        cout << "choose action" << endl;
        cout << "1. Find by key\n"
                "2. Add element\n"
                "3. Dell element\n"
                "4. print tree\n"
                "5. median rotation\n"
                "6. Exit" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "enter key" << endl;
                cin >> key;
                cout << tree.find(stoi(key)).print() << endl;
                break;
            case 2:
                cout << "enter uiser" << endl;
                data = Data(true);
                tree.add(data);
                break;
            case 3:
                cout << "enter key" << endl;
                cin >> key;
                tree.dell(stoi(key));
                break;
            case 4:
                tree.print();
                break;
            case 5:
                cout << tree.median_rotations()<< endl;
                break;
            case 6:
                exit = true;
                break;
            default:
                cout << "wrong choose" << endl;
                return;
        }
    }
}
