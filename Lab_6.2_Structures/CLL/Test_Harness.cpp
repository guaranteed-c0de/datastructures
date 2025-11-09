#include "SCLL.h"
#include <iostream>
using namespace std;

int main() {
    SCLL Riku;
    
    Riku.SortedInsert(4);
    Riku.SortedInsert(3);

    Riku.Print();
   cout << "The length of the list is " << Riku.DetectLoopLength() << endl;
}