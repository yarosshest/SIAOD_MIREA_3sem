//
// Created by yaros on 28.11.2022.
//
#include <string>
#include <list>
#include <utility>
#include <vector>
using namespace std;

struct Node77{
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


    //Метод сдвига буфера
    //Принимает количество символов, на которое нужно сдвинуть буфер. Позиция сдвигается на это количество символов вперед, в буфер записываются новые символы из строки
    void shift(int x){
        pos += x;
        if (pos < size){
            buffer = str.substr(0,pos);
        } else {
            buffer = str.substr(pos - size,size);
        }
    }

    Buffer(string str, int size){
        this->str = std::move(str);
        this->size = size;
        buffer = "";
    }
};

struct LZ77{
    string code;
    list<Node77> listEncode;

    //Метод кодирования LZ77
    //Пока не закончится строка, берется подстрока, которая ищется в буфере, если находится, то сдвигаем буфер на длину
    // найденной подстроки, иначе сдвигаем на 1 символ вперед и записываем в список кодирования найденную подстроку и следующий символ из строки (если он есть)
    string encode(string line, int size){
        Buffer buffer(line, size);
        list<Node77> res;
        while (buffer.pos < line.size()){
            int offset = 0;
            int length = 0;
            char next = ' ';
            for (int i = 0; i < buffer.buffer.size(); i++){
                int j = 0;

                while (buffer.buffer[i + j % (buffer.buffer.size() - i)] == line[buffer.pos + j ])
                    j++;

                if (j >= length && j != 0){
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
        code = result;
        listEncode = res;
        return result;
    }

    //Метод декодирования LZ77
    //Проходя по списку кодирования, берется подстрока из буфера, которая соответствует offset и length, и записывается
    // в строку декодирования и сдвигается буфер на длину найденной подстроки + 1 символ (если он есть)
    string decode(){
        string res = "";
        for (auto & i : listEncode){
            if (i.length == 0){
                res += i.next;
            } else {
                for (int j = 0; j < i.length; j++){
                    res += res[res.size() - i.offset];
                }
                res += i.next;
            }
        }
        return res;
    }
};
