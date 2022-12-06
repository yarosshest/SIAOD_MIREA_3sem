
#include <iostream>
#include <string>
#include "RLE.cpp"
#include "LZ77.cpp"
#include "LZ78.cpp"
#include "ShannonFano.cpp"
#include "Huffman.cpp"
#include <clocale>
#include <fstream>

using namespace std;

void testRLE() {
    string repit = "aaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccc";
    string nonRepit = "abcqwertyuiopasdfghjkl;'zxcvbnm,.1234567890abcqwertyuiopasdfghjkl;'zxcvbnm,*";



    cout << "a long series of repetitive characters: " << repit << endl;
    cout << "a long series of non-repetitive characters: " << nonRepit << endl;
    cout << "RLE" << endl;
    float repitRLE = RLE(repit);
    float nonRepitRLE = RLE(nonRepit);
    cout << "a long series of repetitive characters: " << repit << endl;
    cout << "compression: "<< repitRLE << endl;
    cout << "a long series of non-repetitive characters: " << nonRepit << endl;
    cout << "compression: "<< nonRepitRLE << endl;
}

void testLZ77() {
    LZ77 lz77;
    string line = "110101011001100001001";
    string code = lz77.encode(line, 5);
    cout << "line: " << line << endl;
    cout << "LZ77" << endl;
    cout << "code: " << code << endl;
    cout << "compression: " << code.size()/line.size() << endl;

}

void testLZ78() {
    LZ78 lz78;
    wstring line = L"долделдолдилделдил";
    wstring code = lz78.encode(line);
    cout << "line: ";
    wcout << line ;
    cout << endl;
    cout << "LZ78" << endl;
    cout << "code: " ;
    wcout << code ;
    cout << endl;
    cout << "compression: " << code.size()/line.size() << endl;
}


void testShannonFano() {
    ShannonFano shannonFano;
    wstring line = L"Тише, мыши, кот на крыше, \n"
                  "А котята ещё выше. Кот пошёл за молоком, \n"
                  "А котята кувырком.";
    string code = shannonFano.encode(line);
    cout << "line: ";
    wcout << line ;
    cout << endl;
    cout << "ShannonFano" << endl;
    cout << "code: " << code << endl;
    cout << "compression: " << shannonFano.getfactor() << endl;
    cout << "code formation table" << endl;
    shannonFano.getTable();

}


void testHuffman() {
    Huffman huffman;
    wstring line = L"Шестаков Ярослав Евгеньевич";
    string code = huffman.encode(line);
    cout << "line: ";
    wcout << line ;
    cout << endl;
    cout << "Huffman" << endl;
    cout << "code: " << code << endl;
    cout << "code formation table" << endl;
    huffman.getTable();
    cout << "compression: " << huffman.getfactor() << endl;
    cout << "the average length of the code: " << huffman.getMedian() << endl;
    cout << "dispersion: " << huffman.getDispersia() << endl;
}

void testFile(){
    wifstream file (R"(C:\Users\yaros\CLionProjects\SIAOD_MIREA_3sem\Lab7\test_100000.txt)");
    wstringstream ss;
    ss << file.rdbuf();
    wstring line = ss.str();
    Huffman huffman;
    string code = huffman.encode(line);
    cout << "compression: " << huffman.getfactor() << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
//    testRLE();
//    testLZ77();
//    testLZ78();
//    testShannonFano();
//    testHuffman();
    testFile();
    return 0;
}