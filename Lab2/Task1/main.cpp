#include "TextWriter.h"
using namespace std;
int main()
{
    TextWriter::createFile("src.txt");
    TextWriter::output("src.txt");
    cout << TextWriter::readById("src.txt", 5);
    return 0;
}