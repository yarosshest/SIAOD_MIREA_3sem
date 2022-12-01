
#include <iostream>
#include <string>
#include "RLE.cpp"
#include "LZ77.cpp"
#include "LZ78.cpp"
#include "ShannonFano.cpp"
#include <clocale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    wstring n;
    n = L"долделдолдилделдил";
//    cin >> n;
//    float k;
//    k = RLE(n);
//    cout <<' '<< n;
    ShannonFano sf;
    cout << sf.encode(n);
//    cout << lz.decode();
//    LZ78 lz;
//    cout << lz.encode(n);
    return 0;
}