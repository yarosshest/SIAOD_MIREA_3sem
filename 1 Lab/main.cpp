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
    int mask = 1<<31;
    mask >>= 31-n;
    return x&~mask;
}

int main() {
    int x;
    cin >> x;
    cout << bitset<32>(x) << endl;
    x = to_zero_n(x, 3);
    cout << bitset<32>(x)<< endl;
}
