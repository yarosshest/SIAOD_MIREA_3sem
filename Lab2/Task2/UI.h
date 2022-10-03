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
    string menu = "1. Запись в бинарный файл из текстового\n"
                  "2. Запись из бинарного файла в текстовый\n"
                  "3. Вывод всех записей двоичного файла\n"
                  "4. Чтение из бинарного файла по индексу\n"
                  "5. Удаление из бинарного файла по индексу\n"
                  "6. Заменить даты техосмотра у автомобиля с заданным номером на новую дату\n"
                  "7. Вывод списока авто одной модели, прошедших техосмотр в заданную дату.\n";
public:
    void start();

};


#endif //SIAOD_UI_H
