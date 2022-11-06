#include "UI.h"
void UI::start() {
    TreeAVL tree;
    vector<char> keys;
    while (!isExit){
        cout << menu;
        cout << "Enter the number of the task: ";
        cin >> task;
        switch (task) {
            case 1: {
                cout << "Enter the number of elements: ";
                cin >> n;
                while (n > 0) {
                    char key = 97 + rand() % 26;
                    if (find(keys.begin(), keys.end(), key) == keys.end()) {
                        keys.push_back(key);
                        n = n-1;
                    }
                }
                sort(keys.begin(), keys.end());
                tree = TreeAVL(keys);
                cout << "Tree created" << endl;
                break;
            }
            case 2: {
                char x;
                cout << "Enter the value: ";
                cin >> x;
                cout << "The level is: " << tree.height(x) << endl;
                break;
            }
            case 3: {
                cout << "The number of elements in the left subtree: " << tree.countLeft() << endl;
                break;
            }
            case 4: {
                cout << "Tree: " << endl;
                tree.printLeft();
                break;
            }
            case 5: {
                cout << "Tree: " << endl;
                tree.printHigh();
                break;
            }
            default: {
                isExit = true;
                break;
            }
        }
    }
}
