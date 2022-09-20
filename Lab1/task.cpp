#include <iostream>
#include <bitset>

using namespace std;


int to_ones(int x){
    int a = 1<<16;
    int b = 1<<14;
    int c = 1;

    return x|a|b|c;
}

int to_zeros(int x){
    int mask = 7<<1;
    mask = ~mask;
    return x&mask;
}

int mult(int x){
    return x << 6;
}

int division(int x){
    return x >> 6;
}

int to_zero_n(int x,int n){
    unsigned int mask = 1<<31;
    mask >>= 31-n;
    return x&~mask;
}

void ui(){
    cout << "Input task number: ";
    int num;
    int val;
    cin >> num;
    switch (num) {
        case 1:
            cout << "Input value: ";
            cin >> val;
            cout << "Input :" << bitset<32>(val)<< endl;
            cout <<"Result : "<< bitset<32>(to_ones(val))<< endl;
            break;
        case 2:
            cout << "Input value: ";
            cin >> val;
            cout << "Input :" << bitset<32>(val)<< endl;
            cout <<"Result : "<< bitset<32>(to_zeros(val))<< endl;
            break;
        case 3:
            cout << "Input value: ";
            cin >> val;
            cout << "Input :" << bitset<32>(val)<< endl;
            cout <<"Result : "<< bitset<32>(mult(val))<< endl;
            break;
        case 4:
            cout << "Input value: ";
            cin >> val;
            cout << "Input :" << bitset<32>(val)<< endl;
            cout <<"Result : "<< bitset<32>(division(val))<< endl;
            break;
        case 5:
            cout << "Input value: ";
            cin >> val;
            int n;
            cout << "Input n: ";
            cin >> n;
            cout << "Input :" << bitset<32>(val)<< endl;
            cout <<"Result : "<< bitset<32>(to_zero_n(val, n))<< endl;
            break;

    }
}