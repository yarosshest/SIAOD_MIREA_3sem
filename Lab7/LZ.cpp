//
// Created by yaros on 28.11.2022.
//
#include <string>
#include <list>
#include <utility>
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
    int size;
public:
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
        this->str = std::move(str);
        this->size = size;
        buffer = "";
    }
};




string LZ77 (string line, int size){
    Buffer buffer(line, size);
    list<Node> res;
    while (buffer.pos < line.size()){
        int offset = 0;
        int length = 0;
        char next = ' ';
        for (int i = 0; i < size; i++){
            int j = 0;
            char a = buffer.buffer[(i + j) % (size - 1)];
            char b = line[buffer.pos + j];
            while (buffer.buffer[(i + j) % (size - 1)] == line[buffer.pos + j]){
                j++;
            }
            if (j > length){
                length = j;
                offset = buffer.buffer.size() - i;
                next = line[buffer.pos + j];
            }
        }
        if (length == 0)
            next = line[buffer.pos];
        res.push_back({offset,length,next});
        buffer.shift(length + 1);
    }
    string result = "";
    for (auto & i : res){
        result += i.toString();
    }
    return result;
}