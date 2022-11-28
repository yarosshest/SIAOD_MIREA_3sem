//
// Created by yaros on 28.11.2022.
//
#include <string>
#include <list>
using namespace std;

struct Node{
    int offset;
    int length;
    char next;

    string toString(){
        return '{' + to_string(offset) +','+ to_string(length) +','+ next +'}';
    }
};

struct Buffer{
private:
    string str;
public:
    int size = 0;
    string buffer;
    int pos = 0;

    void shift(int x){
        pos += x;
        if (pos < size){
            buffer = str.substr(0,pos);
        } else {
            buffer = str.substr(pos - size,pos);
        }
    }

    Buffer(string str, int size){
        this->str = str;
        this->size = size;
        buffer = "";
    }

    int, int find(string str){
        int pos = str.find(buffer);
        if (pos != -1){
            return pos;
        }
        return str.find(buffer.substr(1));
    }
};




string LZ77 (string line){
    list<Node> res;
    int pos = 1;
    Buffer buffer = Buffer(line, line.size()/2 );
    buffer.shift(1);
    res.push_back(Node{0,0,line[0]});
    while (pos < line.size()){
        offset, length = findMatching(buffer, pos)
    }
}