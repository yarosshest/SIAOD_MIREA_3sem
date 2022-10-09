//
// Created by yaros on 30.09.2022.
//

#include "UI.h"
#include "BinWriter.h"
void UI::start() {
    while (!isExit)
    {
        cout << menu << endl;
        cout << "Enter the operation number" << endl;
        cin >> task;
        switch (task) {
            case 1:
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                bw.writeBin(name, nameBin);
                cout << "In a binary file " << nameBin << " the data from the text file is written in " << name << endl;
                cout << "Data: " << endl;
                bw.outputBin(nameBin);
                break;
            case 2:
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                bw.writeSource(nameBin, name);
                cout << "Data from a binary file " << nameBin << " Recorded in a text file "<< name << endl;
                break;
            case 3:
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                cout << "Data from a binary file " << nameBin << endl;
                bw.outputBin(nameBin);
                break;
            case 4:
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                cout << "Enter index" << endl;
                cin >> index;
                cout << "Data from a binary file " << nameBin << " by index " << index << endl;
                cout <<bw.readAuto(nameBin, index)->out() << endl;
                break;
            case 5:
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                cout << "Enter index" << endl;
                cin >> index;
                bw.dellAuto(nameBin, index);
                cout << "Data from a binary file " << nameBin << endl;
                bw.outputBin(nameBin);
                break;
            case 6:
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                cout << "Enter region" << endl;
                cin >> reg;
                cout << "Enter number" << endl;
                cin >> num;
                cout << "Enter a letter" << endl;
                cin >> buk;
                cout << "Enter date" << endl;
                cin >> date;
                bw.rep(date, reg, num, buk, nameBin);
                cout << "Data from a binary file " << nameBin << endl;
                bw.outputBin(nameBin);
                break;
            case 7:
                cout << "Enter binary file name" << endl;
                cin >> nameBin;
                cout << "Enter date" << endl;
                cin >> date;
                cout << "Enter model" << endl;
                cin >> mod;
                bw.showMod(date, mod, nameBin);
                break;
            default:
                isExit = true;
                break;
        }
    }
}
