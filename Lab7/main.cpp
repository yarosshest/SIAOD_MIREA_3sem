
#include <iostream>
#include <string>
#include "RLE.cpp"
#include "LZ.cpp"
using namespace std;
int main() {
    string n;
    cin >> n;
//    float k;
//    k = RLE(n);
//    cout << k << ' '<< n;

    cout << LZ77(n, 5);
    return 0;
}