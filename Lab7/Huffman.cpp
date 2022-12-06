//
// Created by yaros on 01.12.2022.
//
#include <string>
#include <map>
#include <vector>
#include "Tree/record.h"
#include "Tree/Tree.h"
#include "Tree/node.h"
using namespace std;
struct Huffman{
    wstring line;
    string code;
    map<wchar_t, string> codes;
    map<wchar_t, int> dict;

    float getfactor(){
        float iput = line.size() *16;
        float oput = code.size();
        return oput/iput;
    }

    float getMedian(){
        float median = 0;
        for (pair<wchar_t, string> i: codes) {

            median += (float) i.second.size()*((float) dict[i.first] /(float) line.size());
        }
        return median;
    }

    float getDispersia(){
        float average = getMedian();
        float disp = 0;
        for(pair<const wchar_t, basic_string<char>> i : codes)
            disp += (float) dict[i.first] /(float) line.size() *((float) i.second.size() - average)*((float) i.second.size() - average);
        return disp;
    }

    void getTable() {
        for (pair<wchar_t, string> i: codes) {
            wcout << i.first << " ";
            cout << dict[i.first] << " ";
            cout << (float) dict[i.first] /(float) line.size() << " ";
            cout << i.second << endl;
        }
    }

    //функция кодирования Хаффмана
    //принимает строку, проходя по строке считает частоту символов и записывает в словарь dict в виде пары символ-частота
    //затем сортирует словарь по частоте символов и записывает в вектор keys в виде структуры record (символ-частота)
    //После строитсе дерево Хаффмана по вектору keys и записывает в словарь codes в виде пары символ-код
    //затем проходя по строке кодирует ее и записывает в строку code

    string encode(wstring ln){
        line = ln;
        for(wchar_t i : line)
            if (dict.count(i) == 0)
                dict[i] = 1;
            else
                dict[i]++;

        vector<record> keys;
        for(pair<wchar_t, int> i : dict)
            keys.emplace_back(i.first, i.second);

        vector<node*> nodes;
        for(record i : keys){
            vector<record> temp = {i};
            nodes.emplace_back(new node(temp));
        }
        while(nodes.size() > 1){
            sort(nodes.begin(), nodes.end(), [](node* a, node* b){return a->getWeight() > b->getWeight();});
            node* left = nodes.end() [-2];
            node* right = nodes.end() [-1];
            vector<record> buf = left->info;
            buf.insert(buf.end(), right->info.begin(), right->info.end());
            nodes.pop_back();
            nodes.pop_back();
            nodes.emplace_back(new node(buf, left, right));
        }
        nodes[0]->getCodes(codes, "");
        for(wchar_t i : line)
            code += codes[i];
        return code;
    }
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