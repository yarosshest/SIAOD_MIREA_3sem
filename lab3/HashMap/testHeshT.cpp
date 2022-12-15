#include <iostream>
#include <string>
#include "HeshTable.h"

using namespace std;


int testhesh()
{
	HeshTable ht;

	ht.Insert("test", 1);
	ht.Output();
	ht.Insert("test_end", 999);
	ht.Insert("test_midl", 12);
	ht.Insert("test", 1);
	ht.Insert("test", 1);
	ht.Insert("test", 1);
	ht.Output();

	for (int i = 0; i < 10; i++) {
		ht.Insert("test_for", i);
	}

	ht.Output();

	cout << "Remove 'test_midl'" << endl;
	ht.Remove("test_midlt");

	ht.Output();

	string line= "test";

	cout << "===========" << endl;
    cout << ht.GetShift(line.c_str()) << endl;
    cout << "===========" << endl;

	ht.Output();

	return 0;
}
