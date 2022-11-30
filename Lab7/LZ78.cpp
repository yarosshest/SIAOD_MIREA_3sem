//
// Created by yaros on 29.11.2022.
//
#include <string>
#include <list>
#include <utility>
#include <vector>
using namespace std;

struct Node78{
    int link;
    string next;

    string toString(){
        return '{' + to_string(link) +','+ next +'}';
    }
};

struct LZ78{
    string code;
    list<Node78> listEncode;
    string encode(string line){
        list<string> dict;
        list<Node78> res;
        int pos = 0;
        while (pos < line.size()){
            string buffer = "";
            int link = 0;
            int l = 1;
            int length = 0;
            string next = " ";

            for (auto & i : dict){

                int j = 0;
                while (i[j] == line[pos + j])
                    j++;
                if (j > length && j != 0){
                    length = j;
                    link = l;
                    next = line[pos + j];
                    buffer = i + next;
                }
                l++;
            }
            if (length == 0)
            {
                next = line[pos];
                buffer = next;
            }
            res.push_back({link,next});
            dict.push_back(buffer);
            pos += length + 1;
        }

        string result = "";
        for (auto & i : res){
            result += i.toString();
        }
        code = result;
        listEncode = res;
        return result;
    }

    string decode(){
        vector<string> dict;
        string res = "";
        for (auto & i : listEncode){
            if (i.link == 0){
                res += i.next;
                dict.push_back(i.next);
            } else {
                res += dict[i.link - 1] + i.next;
                dict.push_back(dict.front() + i.next);
            }
        }
        return res;
    }
};