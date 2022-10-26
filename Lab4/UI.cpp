#include "UI.h"
void UI::start() {
    int n;
    cout << "input n:  " << endl;
    n  = 26;
    vector<char> keys;
    while (n > 0) {
        char key = 97 + rand() % 26;
        if (find(keys.begin(), keys.end(), key) == keys.end()) {
            keys.push_back(key);
            n = n-1;
        }
    }
    sort(keys.begin(), keys.end());
    Tree tree = Tree(keys);
    cout << tree.print();

    cout << "input char:  " << endl;
    char x;
    cin >> x;
    cout << "height: " << tree.height(x) << endl;
    cout << "count left: " << tree.countLeft() << endl;
}
