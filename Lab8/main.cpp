
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ingredient {
    int calories;
    int fat;

    ingredient(int c, int f) {
        calories = c;
        fat = f;
    }

    ingredient() {
        calories = NULL;
        fat = NULL;
    }

    bool operator<(const ingredient& other) const {
        return (float)fat/(float)calories < (float)other.fat/(float)other.calories;
    }

    bool operator>(const ingredient& other) const {
        return (float)fat/(float)calories > (float)other.fat/(float)other.calories;
    }

    bool operator==(const ingredient& other) const {
        return (float)fat/(float)calories == (float)other.fat/(float)other.calories;
    }

    bool operator!=(const ingredient& other) const {
        return (float)fat/(float)calories != (float)other.fat/(float)other.calories;
    }

    bool operator<=(const ingredient& other) const {
        return (float)fat/(float)calories <= (float)other.fat/(float)other.calories;
    }

    bool operator>=(const ingredient& other) const {
        return (float)fat/(float)calories >= (float)other.fat/(float)other.calories;
    }

friend ostream& operator<<(ostream& os, const ingredient& obj) {
        os << obj.calories << " " << obj.fat;
        return os;
    }

};


//жадный агоритм
int greedy(vector<ingredient> p, int q){
    sort(p.begin(), p.end(), greater<>());
    int sum = 0;
    int fat = 0;
    ingredient big;
    for (ingredient i : p) {
        if (i.calories <= q && i.fat > big.fat) {
            big = i;
        }
        if (q >= sum + i.calories) {
            sum += i.calories;
            cout << i << endl;
            fat += i.fat;
        }
    }
    if (big.fat > fat) {
        cout << "Max fat: " << big << endl;
        fat = big.fat;
    }
    return fat;
}

//обычный алгоритм
int normal(int *a, int n, int k){
    int res = 0;
    for (int i = 0; i < n; i++){
        res += a[i];
        if (res >= k){
            return i + 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<ingredient> p;
    p.emplace_back(10, 100);
    p.emplace_back(20, 200);
    p.emplace_back(30, 300);
    p.emplace_back(40, 400);
    p.emplace_back(50, 500);
    p.emplace_back(10, 600);
    p.emplace_back(20, 700);
    p.emplace_back(30, 800);
    p.emplace_back(40, 900);
    int q = 100;
    int fat = greedy(p, q);
    cout << "Sum fat: " <<fat;


    return 0;
}