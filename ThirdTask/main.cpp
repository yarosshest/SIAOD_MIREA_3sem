#include <iostream>
#include "Data.h"
using namespace std;

int main(int argc, char **argv)
{
    Data dt("bin", "txt.txt");
    int a = dt.GetSizeFile();
    for (unsigned i = 0; i < dt.GetSizeFile()-1; i++)
        dt.SaveEntry(i);
    cout << "====" << endl;
    cout << dt.Search(argv[1]).toString() << endl;
    dt.Remove(argv[1]);
    dt.Output();

    return 0;
}