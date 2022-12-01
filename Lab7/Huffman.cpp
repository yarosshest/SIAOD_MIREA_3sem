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
        nodes[0]->printLeft();
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