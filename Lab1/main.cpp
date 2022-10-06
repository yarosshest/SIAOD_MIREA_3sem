#include <iostream>

using namespace std;

void printBitset(int b) {
    for (int i = 31; i >= 0; i--) {
        cout << ((b >> i) & 1);
    }
}

void to_ones(int x){
    int a = 1<<8;
    int b = 1<<5;
    int c = 1;
    int mask = a | b | c;
    cout << "Mask:   ";
    printBitset(mask);
    cout << endl;
    cout << "Result: ";
    printBitset(x | mask);
}

void to_zeros(int x){
    int a = 1<<8;
    int b = 1<<5;
    int c = 1;
    int mask = a | b | c;
    mask = ~mask;
    cout << "Mask:   ";
    printBitset(mask);
    cout << endl;
    cout << "Result: ";
    printBitset(x & mask);
}

void mult(int x){
    x = x << 3;
    cout << "Result: " << x << endl;
}

void division(int x){
    x =  x >> 3;
    cout << "Result: " << x << endl;
}

void to_zero_n(int x,int n){
    unsigned int mask = 1;
    mask <<= n-1;
    mask = ~mask;
    cout << "Mask:   ";
    printBitset(mask);
    cout << endl;
    cout << "Result: ";
    printBitset(x & mask);
}

void ui(){
    cout << "Input task number: \n";
    int num;
    int val;
    cin >> num;
    cout << "Input value: \n";
    cin >> val;
    switch (num) {
        case 1:
            cout << "Input:  " ;
            printBitset(val);
            cout << endl;
            to_ones(val);
            break;
        case 2:
            cout << "Input:  " ;
            printBitset(val);
            cout << endl;
            to_zeros(val);
            break;
        case 3:
            cout << "Input:  " ;
            cout << val << endl;
            mult(val);
            break;
        case 4:
            cout << "Input:  " ;
            cout << val << endl;
            division(val);
            break;
        case 5:
            int n;
            cout << "Input N: \n";
            cin >> n;
            cout << "Input:  " ;
            printBitset(val);
            cout << endl;
            to_zero_n(val, 5);
            break;

    }
}

int main()
{
    ui();
}