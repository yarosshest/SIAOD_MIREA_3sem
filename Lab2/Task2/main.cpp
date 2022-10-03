#include "ReaderSource.h"
#include "BinWriter.h"

using namespace std;
int main()
{

    BinWriter bw = BinWriter();
    bw.writeBin("src.txt", "bin");
    bw.outputBin("bin");
    cout << "-----------------" << endl;
    bw.dellAuto("bin", 1);
    bw.outputBin("bin");
    return 0;
}
