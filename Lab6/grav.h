//
// Created by yaros on 17.11.2022.
//

#ifndef SIAOD_GRAF_H
#define SIAOD_GRAF_H
#include <iostream>
using namespace std;
class grav {
    int **matrix;
    int size;
public:
    grav();
    void addEdge(int a, int b, int weight);
    void print();
    bool connected();
    void deppTeb(int a, bool *visited);
    int diikstra(int a, int b);

};


#endif //SIAOD_GRAF_H
