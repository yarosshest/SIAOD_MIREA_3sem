#include "ReaderSource.h"
#include "BinWriter.h"
//#include "task2.cpp"

using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    ReaderSource readerSource = ReaderSource();
    vector<Auto> autos = readerSource.readSource("src.txt");
    BinWriter binWriter = BinWriter();
    binWriter.writeBin("bin", autos);
    binWriter.outputBin("bin");
    binWriter.writeAuto("bin.txt",autos[0], 1);
    binWriter.outputBin("bin.txt");
    return 0;
}
