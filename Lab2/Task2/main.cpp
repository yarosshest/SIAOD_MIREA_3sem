#include "ReaderSource.h"
#include "BinWriter.h"
#include "task2.cpp"

using namespace std;
int main()
{
    ReaderSource readerSource = ReaderSource();
    vector<Auto> autos = readerSource.readSource("src.txt");
    UserWriteByNum("343", autos, "result.txt");
    return 0;
}
