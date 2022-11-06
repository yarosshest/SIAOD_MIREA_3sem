#include <iostream>
#include "Data.h"

using namespace std;

void Data::SaveEntry(int shift)
{
	Auto ph = *file.readAuto(shift);
	table.Insert(ph.id.c_str(), shift);
}

void Data::Remove(const char *id)
{
	file.dellAuto((int) id);
	table.Remove(id);
}

Auto Data::Search(const char *id)
{
	int shift = table.GetShift(id);
	return *file.readAuto(shift);
}

void Data::Output() const
{
	cout << "=====" << endl;
	cout << "+@+@+File: " << endl;
	file.outputBin();
	cout << "+@+@+Table: " << endl;
	table.Output();
	cout << "=====" << endl;
}

Data::Data(string bin, string txt) : table() {
    file = BinWriter(bin, txt);
}
