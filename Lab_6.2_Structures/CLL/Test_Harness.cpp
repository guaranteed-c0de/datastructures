#include "SCLL.h"
#include <iostream>
using namespace std;

int main() {
    SCLL Riku;
    for (int i = 1; i<= 7; i++)
    {
        Riku.InsertTail(i);
    }
    Riku.Print();
    cout << "\nThe survivor is " << Riku.Josephus(3) << endl;
}