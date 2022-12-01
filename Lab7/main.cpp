
#include <iostream>
#include <string>
#include "RLE.cpp"
#include "LZ77.cpp"
#include "LZ78.cpp"
#include "ShannonFano.cpp"
#include "Huffman.cpp"
#include <clocale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    wstring n;
    n = L"Тише, мыши, кот на крыше, \n"
        "А котята ещё выше. Кот пошёл за молоком, \n"
        "А котята кувырком.";
//    cin >> n;
//    float k;
//    k = RLE(n);
//    cout <<' '<< n;
    Huffman hf;
    string code = hf.encode(n);
    cout << code << endl;
    wcout << hf.decode(code) << endl;
//    cout << lz.decode();
//    LZ78 lz;
//    cout << lz.encode(n);
    return 0;
}