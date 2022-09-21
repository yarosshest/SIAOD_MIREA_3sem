#include "task.cpp"
#include "ReaderSource.h"
#include <string>
using namespace std;
int main()
{
    ReaderSource reader = ReaderSource();
    vector<Auto> a =  reader.readSource();
    cout << a.size();
}
