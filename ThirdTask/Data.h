#ifndef DATA_FILE_H
#define DATA_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include "./binFile/BinWriter.h"
#include "./binFile/Auto.h"
#include "./HashMap/HeshTable.h"

class Data
{
    BinWriter file;
	HeshTable table;
public:
	Data(std::string bin, std::string txt);
	Data(BinWriter bf): file(bf), table() {}
	void SaveEntry(const int shift);
	void Remove(const char *id);
	Auto Search(const char *id);
	void Output() const;
};

#endif
