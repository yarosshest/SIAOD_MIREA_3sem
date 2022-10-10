//
// Created by yaros on 30.09.2022.
//
#include "TextWriter.h"
#include "UI.h"
void UI::start() {
    while (!isExit){
        cout << menu << endl;
        cout << "Enter the operation number" << endl;
        cin >> task;
        switch (task) {
            case 1:
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                TextWriter::createFile(name);
                break;
            case 2:
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                TextWriter::output(name);
                break;
            case 3:
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                cout << "Enter the line" << endl;
                getline(cin, line);
                getline(cin, line);
                TextWriter::addLastRow(name, line);
                break;
            case 4:
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                cout << "Enter index" << endl;
                cin >> index;
                cout << TextWriter::readById(name, index) << endl;
                break;
            case 5:
                cout << "Enter the name of the text file" << endl;
                cin >> name;
                cout << TextWriter::getVolume(name)<< endl;
                break;
            default:
                isExit = true;
                break;

        }
    }
}
