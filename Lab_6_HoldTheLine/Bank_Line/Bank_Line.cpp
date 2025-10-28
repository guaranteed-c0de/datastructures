#include <iostream>
using namespace std;
#include "QueType.h"
void Display(QueType& queue);
int main() {
    
    QueType BankQueue(10);
   Display(BankQueue);
   return 0;
}

void Display(QueType& queue) {
int Service_Rate = 3;
int Arrival_Rate = 2 * Service_Rate;

for (int i = 1; i<= 100; i++)
{
    int LeftLine = 0;
    int NoOneToServe = 0;
    for (int x = 0; x < Arrival_Rate; x++)
    {
        if (queue.IsFull())
        {
            LeftLine +=1;
        }
        queue.Enqueue(queue.GenerateItem());

    }
    for (int y = 0; y < Service_Rate; y++)
    {
       
         queue.Dequeue();
}
if (queue.IsEmpty())
{
    NoOneToServe +=1;
}
cout << "This is iteration " << i << ".\n";
cout << LeftLine << " patrons left the line." << endl;
cout << "So far, the customer service desks have been empty " << NoOneToServe << " times!" << endl;
cout << "There are " << queue.GetLength() << " people currently in line.\n\n";
}

}