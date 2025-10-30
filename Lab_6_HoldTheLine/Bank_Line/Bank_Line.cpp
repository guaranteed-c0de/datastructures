#include <iostream>
using namespace std;
#include "QueType.h"
#include <cstdlib>
#include <ctime>
#include <random>
void ShowData(QueType& queue);
int main() {
    
    QueType BankQueue(10);
   ShowData(BankQueue);
   return 0;
}

void ShowData(QueType& queue) {

int Arrival_Rate;
int Service_Rate;
int TotalLeftLine = 0;
int TotalServed = 0;
int NoOneToServe = 0;
   std::random_device rd;  // non-deterministic random seed
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    std::uniform_int_distribution<> dist(0, 9); 

for (int i = 1; i<= 100; i++)
    
{
   
    Arrival_Rate = dist(gen);
    cout << "Arrival Rate: " << Arrival_Rate << endl;
    Service_Rate = Arrival_Rate/2;
    double proxy_Service_Rate = static_cast<double>(Arrival_Rate)/2;
    if (proxy_Service_Rate != Service_Rate)
    {
        Service_Rate++;
    }
    
    cout << "Service Rate: " << Service_Rate << endl;
    int LeftLine = 0;
    for (int x = 0; x < Arrival_Rate; x++)
    {
        if (!queue.IsFull()) {
        queue.Enqueue(queue.GenerateItem()); 
            }
        else {
            
            LeftLine++;
        }
         
    }
   TotalLeftLine += LeftLine;
   
if (queue.IsEmpty())
{
    NoOneToServe +=1;
}
else {
 for (int y = 0; y < Service_Rate; y++)
    {
       
         queue.Dequeue();
         TotalServed +=1;
}
}
cout << "This is iteration " << i << ".\n";
cout << TotalServed << " patrons have been served.\n";
cout << TotalLeftLine << " patrons left the line." << endl;
cout << "So far, the customer service desks have been empty " << NoOneToServe << " times!" << endl;
cout << "There are " << queue.GetLength() << " people currently in line.\n";
cout << "This is the current queue:\n";
queue.DisplayQueue();
cout << endl;
}

}

