#include "task.cpp"
#include "ReaderSource.h"
#include <string>
using namespace std;
int main()
{
    ReaderSource reader = ReaderSource();
    reader.readSource("Source.txt");
}
