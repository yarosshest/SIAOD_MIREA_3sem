#include "UI.h"
void UI::start() {
    int n;
    cout << "input n:  " << endl;
    n  = 50;
    Tree tree;
    vector<char> keys;
    while (n >= 0) {
        char key = 97 + rand() % 26;
        if (find(keys.begin(), keys.end(), key) == keys.end()) {
            tree.add(key);
            n = n-1;
        }
    }
    tree.print();
}
