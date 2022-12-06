//
// Created by yaros on 30.11.2022.
//
#include <string>
#include <map>
#include <vector>
#include "Tree/record.h"
#include "Tree/Tree.h"
using namespace std;
struct ShannonFano{
    wstring line;
    string code;
    map<wchar_t, string> codes;

    float getfactor(){
        float iput = line.size() *16;
        float oput = code.size();
        return oput/iput;
    }

    void getTable() {
        for (pair<wchar_t, string> i: codes) {
            wcout << i.first << " ";
            cout << i.second << endl;
        }
    }

    //функция кодирования Шеннона-Фано
    //принимает строку, проходя по строке считает частоту символов и записывает в словарь dict в виде пары символ-частота
    //затем сортирует словарь по частоте символов и записывает в вектор keys в виде структуры record (символ-частота)
    //После строитсе дерево Шеннона-Фано по вектору keys и записывает в словарь codes в виде пары символ-код
    string encode(wstring ln){
        line = ln;
        map<wchar_t, int> dict;
        for(wchar_t i : line)
            if (dict.count(i) == 0)
                dict[i] = 1;
            else
                dict[i]++;
        vector<record> keys;
        for(pair<wchar_t, int> i : dict)
            keys.emplace_back(i.first, i.second);
        Tree tree(keys);
        tree.printLeft();
        codes = tree.getCodes();
        for(wchar_t i : line)
            code += codes[i];
        return code;
    }

    //функция декодирования Шеннона-Фано
    //принимает строку, проходя по строке считает код и сравновает его с кодами в словаре codes и если совподает то записывает в строку decoded символ из словаря codes и очищает строку temp
    // иначе записывает в строку temp символ из строки
    wstring decode(string cd){
        wstring decoded;
        string temp;
        for(char i : cd){
            temp += i;
            for(pair<wchar_t, string> j : codes)
                if (j.second == temp){
                    decoded += j.first;
                    temp = "";
                }
        }
        return decoded;
    }
};