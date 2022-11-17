//
// Created by yaros on 17.11.2022.
//
#include "Ui.h"


void Ui::start() {
    grav g;
    int a, b, weight;
    bool exit = false;
    while (!exit) {
        cout << "1. Add edge" << endl;
        cout << "2. Print" << endl;
        cout << "3. Connected" << endl;
        cout << "4. Diikstra" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a, b, weight" << endl;
                cin >> a >> b >> weight;
                g.addEdge(a - 1, b - 1, weight);
                break;
            case 2:
                g.print();
                break;
            case 3:
                if (g.connected()) {
                    cout << "Connected" << endl;
                } else {
                    cout << "Not connected" << endl;
                }
                break;
            case 4:
                cout << "Enter a, b" << endl;
                cin >> a >> b;
                cout << g.diikstra(a - 1, b - 1) << endl;
                break;
            case 5:
                exit = true;
                return;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }

}
