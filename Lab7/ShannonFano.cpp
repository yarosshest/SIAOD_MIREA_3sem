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
        map<wchar_t, string> codes = tree.getCodes();
        for(wchar_t i : line)
            code += codes[i];
        return code;
    }
};