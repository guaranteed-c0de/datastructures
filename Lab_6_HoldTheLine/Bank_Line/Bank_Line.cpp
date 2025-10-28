#include <iostream>
using namespace std;
#include "QueType.h"
void Display(QueType& queue);
int main() {
    
    QueType BankQueue(100);
   Display(BankQueue);
   return 0;
}

void Display(QueType& queue) {
int Service_Rate = 3;
int Arrival_Rate = 2 * Service_Rate;
int TotalLeftLine = 0;
int TotalServed = 0;

for (int i = 1; i<= 100; i++)
{
    int LeftLine = 0;
    int NoOneToServe = 0;
    for (int x = 0; x < Arrival_Rate; x++)
    {
        queue.Enqueue(queue.GenerateItem());

    }
    while (queue.GetLength() > 10)
    {
        queue.Dequeue();
        LeftLine +=1;
    }
    TotalLeftLine += LeftLine;
    for (int y = 0; y < Service_Rate; y++)
    {
       
         queue.Dequeue();
         TotalServed +=1;
}
if (queue.IsEmpty())
{
    NoOneToServe +=1;
}
cout << "This is iteration " << i << ".\n";
cout << TotalServed << " patrons have been served.\n";
cout << TotalLeftLine << " patrons left the line." << endl;
cout << "So far, the customer service desks have been empty " << NoOneToServe << " times!" << endl;
cout << "There are " << queue.GetLength() << " people currently in line.\n\n";
}

}