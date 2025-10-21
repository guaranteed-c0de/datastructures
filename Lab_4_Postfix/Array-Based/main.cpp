#include <iostream>
using namespace std;
#include "Stack.h"
int main() {
    Stack Plain;
   /* for (int i = 1; i<= 10; i++) //Push 10 elements (1-10)
    {
        Plain.push(i);
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << Plain.pop();
        cout << endl;
    }*/
   while (true)
   {
    int x = 3;
     if (Plain.isFull())
    {
        break;
    }
    Plain.push(x);
    x++;
   
   }
    return 0;
}
