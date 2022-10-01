#include "ReaderSource.h"
#include "BinWriter.h"

using namespace std;
int main()
{

    BinWriter bw = BinWriter();
    bw.writeBin("src.txt", "bin");
    bw.outputBin("bin");
    bw.writeSource("bin", "src2.txt");
    bw.writeBin("src2.txt", "bin");
    bw.outputBin("bin");
    return 0;
}
