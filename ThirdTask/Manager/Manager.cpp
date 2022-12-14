#include "Manager.h"

using namespace std;

void Manager::SaveEntry(int shift)
{
	Auto ph = *file.readAuto(shift);
	table.Insert(ph.id, shift);
}

void Manager::Remove(const char *id)
{
	file.dellAuto(stoi(id));
	table.Remove(id);
}

Auto Manager::Search(const char *id)
{
	int shift = table.GetShift(id);
	return *file.readAuto(shift);
}

void Manager::Output() const
{
	cout << "=====" << endl;
	cout << "+@+@+File: " << endl;
	file.outputBin();
	cout << "+@+@+Table: " << endl;
	table.Output();
	cout << "=====" << endl;
}

Manager::Manager(string bin, string txt) : table() {
    file = BinWriter(bin, txt);
}
