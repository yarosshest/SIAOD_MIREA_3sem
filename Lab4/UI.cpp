#include "UI.h"
void UI::start() {
    int n;
    cout << "input n:  ";
    cin >> n;
    binary_tree tree;
    vector<char> keys;
    while (n >= 0) {
        char key = 97 + rand() % 26;
        if (find(keys.begin(), keys.end(), key) == keys.end()) {
            tree.insert(key);
            n = n-1;
        }
    }
//    tree.Balance();
    cout << tree.GraphViz() << endl;
}
