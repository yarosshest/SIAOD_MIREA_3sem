//
// Created by yaros on 21.09.2022.
//

#ifndef SIAOD_READERSOURSE_H
#define SIAOD_READERSOURSE_H

#include "Auto.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

class ReaderSource {
private:
    int length;
public:
    vector<Auto> readSource(const string& path);
};


#endif //SIAOD_READERSOURSE_H
