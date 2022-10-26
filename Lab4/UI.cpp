#include "UI.h"
void UI::start() {
    int n;
    cout << "input n: ";
    cin >> n;
    binary_tree tree;
    for (int i = 0; i , n - 1; i++) {
        char key = 97 + rand() % 26;
        tree.insert(key);
    }
    cout << "Tree: " << tree.printLNR() << endl;
}
