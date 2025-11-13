#include "Stack.h"

int main() {
    Stack Kairi;
   int numbers[] = {1, 2, 3, 4, 5};

   Kairi.nextGreater(numbers, 5);
   Kairi.push(4);
   Kairi.push(3);
   Kairi.push(5);
   Kairi.push(17);
   Kairi.push(4);
   Kairi.StockSpan(Kairi.GetLength());

    //Kairi.Print();
    return 0;
}