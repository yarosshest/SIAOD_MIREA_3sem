//
// Created by yaros on 30.09.2022.
//

#include "UI.h"
#include "BinWriter.h"
void UI::start() {
    setlocale(LC_ALL, "Rus");
    cout << menu << endl;
    cout << "Введите номер операции" << endl;
    cin >> task;
    while (!isExit)
    {
        switch (task) {
            case 1:
                cout << "Введите название текстового файла" << endl;
                cin >> name;
                cout << "Введите название бинарного файла" << endl;
                cin >> nameBin;
                bw.writeBin(name, nameBin);
                cout << "В бинарный фаил " << nameBin << " записаны данные из текстового файла " << name << endl;
                cout << "Данные: " << endl;
                bw.outputBin(nameBin);
                break;
            case 2:
                cout << "Введите название бинарного файла" << endl;
                cin >> nameBin;
                cout << "Введите название текстового файла" << endl;
                cin >> name;
                bw.writeSource(nameBin, name);
                cout << "Данные из бинарного файла " << nameBin << " Записанны в текстовый "<< name << endl;
                break;
            case 3:
                cout << "Введите название бинарного файла" << endl;
                cin >> nameBin;
                cout << "Данные из бинарного файла " << nameBin << endl;
                bw.outputBin(nameBin);
                break;
        }
    }
}
