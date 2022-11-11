
#include "ui.h"
int main() {
    ui ui;
    bool exit = false;
    while (!exit){
        cout << "1. Time test\n"
                "2. ui\n"
                "3. exit" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
                ui.timeTest();
                break;
            case 2:
                ui.start();
                break;
            case 3:
                exit = true;
                break;
            default:
                cout << "wrong choose" << endl;
                return 0;
        }
    }
    return 0;
}