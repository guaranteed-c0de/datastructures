#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack Basic;
    for (int x = 0; x < 100; x++)
    {
        Basic.push(x + 1);
    }
    for (int y = 0; y < 100; y++)
    {
        cout << Basic.pop() << endl;
    }
}