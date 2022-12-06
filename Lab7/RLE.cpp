//
// Created by yaros on 28.11.2022.
//
#include <string>

using namespace std;
//функция RLE
//принимает строку, проходя по строке если символ подряд повторяется  то считает сколько раз он повторяется  и записывает в строку
float RLE(string &line) {
    int count = 1;
    int size = line.size();
    string res = "";
    for (int i = 0; i < size; i++) {
        if (line[i] == line[i + 1]) {
            count++;
        } else {
            res += line[i];
            res += to_string(count);
            count = 1;
        }
    }
    line = res;
    return (float) res.size() / size;
}