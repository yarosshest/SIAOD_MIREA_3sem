#ifndef DATA_FILE_H
#define DATA_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "../BinWriter/BinWriter.h"
#include "../Auto.h"
#include "../HashMap/HeshTable.h"
#include <iostream>
#include <cstring>
using namespace std;
class Manager
{
    BinWriter file;
	HeshTable table;
public:
    Manager(string bin, string txt);
	void SaveEntry(const int shift);
	void Remove(const char *id);
	Auto Search(const char *id);
	void Output() const;
    unsigned GetSizeFile() const { return file.GetSize(); }
};

#endif
