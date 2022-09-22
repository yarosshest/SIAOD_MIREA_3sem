#include "task.cpp"
#include "ReaderSource.h"
#include "BinWriter.h"

using namespace std;
int main()
{
//    ReaderSource reader = ReaderSource();
//    vector<Auto> a =  reader.readSource("src.txt");
//    cout << a.size();
    ReaderSource readerSource = ReaderSource();
    BinWriter binWriter = BinWriter();
    vector<Auto> autos = readerSource.readSource("src.txt");
    binWriter.writeBin("bin", autos);
    vector<Auto> autos2;
    binWriter.readBin("bin", autos2);
    if (autos == autos2)
        cout << "OK";
    else
        cout << "ERROR";
}
