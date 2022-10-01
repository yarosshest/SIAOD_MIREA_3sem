//
// Created by yaros on 30.09.2022.
//

#ifndef SIAOD_UI_H
#define SIAOD_UI_H
#include <string>
#include <iostream>
#include "BinWriter.h"
#include "ReaderSource.h"
using namespace std;
class UI {
private:
    string name;
    string nameBin;
    int task;
    BinWriter bw = BinWriter();
    ReaderSource rs = ReaderSource();
    bool isExit = false;
    string menu = "1. Запись в бинарный файл из текстового\n"
                  "2. Запись из бинарного файла в текстовый\n"
                  "3. Вывод всех записей двоичного файла\n"
                  "4. Чтение из бинарного файла по индексу\n"
                  "5. Удаление из бинарного файла по индексу\n"
                  "6. Замена в бинарном файле по индексу\n"
                  "7. Вывод бинарного файла\n"
                  "8. Вывод модели по дате\n"
                  "9. Выход";

public:
    void start();

};


#endif //SIAOD_UI_H
