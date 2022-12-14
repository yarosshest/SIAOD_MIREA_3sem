
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

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
        os << '|' << obj.calories << " " << obj.fat << '|';
        return os;
    }

};


//жадный агоритм
//список ингридиентов сортируется по уменьшению соотношения жиров к калориям. Проходя по списку, провряем самый большой игридет которые помещаетсчяя в блюдо,
// дальше считаем, сколько калорий в блюде, и если оно не превышает заданного, то добавляем ингридиент в блюдо.
//если же превышает, то идем дальше по списку, пока не найдем ингридиент, который поместится в блюдо.
// в итоге получаем список ингридиентов, которые поместились в блюдо. сравниваем сумму жиров в блюде с большим ингридентом и выьираем большее.
vector<ingredient> greedy(vector<ingredient> p, int q){
    vector<ingredient> result;
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
            result.push_back(i);
            fat += i.fat;
        }
    }
    if (big.fat > fat)
        result = {big};
    return result;
}


//рекурсивный алгоритм
//Проверяем остались ли игридеты в списке, если нет, то в результат помещаем список игридиентов, которые поместились в блюдо.
//если же остались, то берем первый ингридиент из списка, и проверяем помещается ли он в блюдо. если помещается, то добавляем его в блюдо и вызываем функцию рекурсивно с новым списком ингридиентов и новым количеством калорий.
//вынимает игридиент из блюда и вызываем функцию рекурсивно с новым списком ингридиентов и новым количеством калорий.
int recursive(vector<ingredient> p, int q, int sum, vector<vector<ingredient>> &res, vector<ingredient> &cur) {
    if (p.empty()) {
        res.push_back(cur);
        return 0;
    }
    else{
        ingredient i = p[0];
        p.erase(p.begin());
        if (sum + i.calories <= q) {
            cur.push_back(i);
            recursive(p, q, sum + i.calories, res, cur);
            cur.pop_back();
        }
        recursive(p, q, sum, res, cur);
    }
    return 0;
}

//Функция  решения полным перебором
//Вызываем рекурсивную функцию, которая возвращает список всех возможных вариантов ингридиентов, которые поместились в блюдо.
//Проходим по списку вариантов и считаем сумму жиров в каждом варианте. выбираем вариант с максимальной суммой жиров.

vector<ingredient> stupid(vector<ingredient> p, int q){
    vector<vector<ingredient>> res;
    vector<ingredient> cur;
    recursive(p, q, 0, res, cur);
    int max = 0;
    vector<ingredient> result;
    for (vector<ingredient> i : res) {
        int fat = 0;
        for (ingredient j : i) {
            fat += j.fat;
        }
        if (fat > max) {
            max = fat;
            result = i;
        }
    }
    return result;
}

void print(vector<vector<ingredient>> res) {
    for (vector<ingredient> i : res) {
        for (ingredient j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
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

    wcout << L"Жадный алгоритм" << endl;
    auto start = chrono::steady_clock::now();
    vector<ingredient> gr = greedy(p, q);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(diff).count() << endl;

    print({gr});

    wcout << L"Рекурсивный алгоритм" << endl;
    start = chrono::steady_clock::now();
    vector<ingredient> st = stupid(p, q);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(diff).count() << endl;

    print({st});

    return 0;
}