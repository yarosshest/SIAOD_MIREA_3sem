#include "UI.h"
void UI::start() {
    int n;
    cout << "input n:  " << endl;
    n  = 26;
    Tree tree;
    vector<char> keys;
    while (n > 0) {
        char key = 97 + rand() % 26;
        if (find(keys.begin(), keys.end(), key) == keys.end()) {
            keys.push_back(key);
            tree.add(key);
            n = n-1;
        }
    }
    tree.balance();
    cout << tree.print();
}
