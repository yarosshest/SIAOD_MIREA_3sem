//
// Created by yaros on 17.11.2022.
//

#include "grav.h"

grav::grav() {
    size = 1;
    matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }
    matrix[0][0] = 0;
}

void grav::addEdge(int a, int b, int weight) {
    if (a >= size || b >= size) {
        int newSize = max(a, b) + 1;
        int **newMatrix = new int *[newSize];
        for (int i = 0; i < newSize; i++) {
            newMatrix[i] = new int[newSize];
            for (int j = 0; j < newSize; j++) {
                newMatrix[i][j] = 0;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        matrix = newMatrix;
        size = newSize;
    }
    matrix[a][b] = weight;
}

void grav::print() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



void grav::deppTeb(int a, bool *visited) {
    visited[a] = true;
    for (int i = 0; i < size; ++i) {
        if (matrix[a][i] > 0 && !visited[i]) {
            deppTeb(i, visited);
        }
    }

}

bool grav::connected() {
    bool *visited = new bool[size];
    for (int i = 0; i < size; ++i) {
        visited[i] = false;
    }

    deppTeb(0, visited);

    bool result = true;
    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return result;
}

int grav::diikstra(int a, int b) {
    int *distance = new int[size];
    bool *visited = new bool[size];
    for (int i = 0; i < size; ++i) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[a] = 0;
    for (int i = 0; i < size; ++i) {
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < size; ++j) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                minIndex = j;
            }
        }
        visited[minIndex] = true;
        for (int j = 0; j < size; ++j) {
            if (!visited[j] && matrix[minIndex][j] > 0 && distance[minIndex] != INT_MAX && distance[minIndex] + matrix[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + matrix[minIndex][j];
            }
        }
    }
    return distance[b];
}
