#include "HashMap/testHeshT.cpp"
#include "BinWriter/testBinf.cpp"
#include "Manager/testManager.cpp"
using namespace std;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Russian");
    testhesh();
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    testBin();
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    testManager();
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    testBigFile();
    return 0;
}