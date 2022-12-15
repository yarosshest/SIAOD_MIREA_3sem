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
    wstring next = L"";

    wstring toString(){
        return L'{' + to_wstring(link) +L','+ next +L'}';
    }
};

struct LZ78{
    wstring code;
    list<Node78> listEncode;

    //Метод кодирования LZ78
    //Пока не закончится строка, берется подстрока, которая ищется в словаре (списке), если находится, то записываем в
    // список кодирования найденную подстроку и следующий символ из строки (если он есть) иначе записываем в список кодирования новую подстроку. Читаем следующие символы из строки
    wstring encode(wstring line){
        list<wstring> dict;
        list<Node78> res;
        int pos = 0;
        while (pos < line.size()){
            wstring buffer = L"";
            int link = 0;
            int l = 1;
            int length = 0;
            wstring next = L" ";

            for (auto & i : dict){

                int j = 0;
                while (i[j] == line[pos + j])
                    j++;
                if (j > length ){
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

        wstring result = L"";
        for (auto & i : res){
            result += i.toString();
        }
        code = result;
        listEncode = res;
        return result;
    }

    //Метод декодирования LZ78
    //Пока не закончится строка, берется подстрока, которая ищется в словаре (списке), если находится, то записываем в
    // строку найденную подстроку и следующий символ из списка кодирования (если он есть) иначе записываем в строку новую подстроку. Читаем следующие символы из списка кодирования и словаря
    wstring decode(){
        vector<wstring> dict;
        wstring res = L"";
        for (auto & i : listEncode){
            if (i.link == 0){
                res += i.next;
                dict.push_back(i.next);
            } else {
                res += dict[i.link - 1] + i.next;
                dict.push_back(dict.front() + i.next);
            }
        }
        wcout << res;
        return res;
    }
};