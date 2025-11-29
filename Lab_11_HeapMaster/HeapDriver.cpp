#include "HeapMaster.h"

int main() {
    HeapMaster<int, 100005, std::greater<int>> Face;

    for (int i = 1; i <= 10; i++)
    {
        Face.push(i);
    }
    Face.printArray();

   cout << "The top of the heap is " <<  Face.top() << endl;
  

   Face.printHeap();
   HeapMaster<Task, 10005, TaskCompare> Priority;

   for (int i = 1; i<= 100; i++) {
    Task x;
    x.id = i;
    x.priority = rand() % 100 + 1;
    x.arrivalTime = rand() % 80 + 1;
    x.burstTime = rand() % 60 + 1;
    x.deadline = rand() % 40 + 1;

    Priority.push(x);
   }
   cout << "This is the heap, in priority.";
for (int i = 0; i<Priority.Getsize(); i++)
{
    Priority.top().print();
    cout << "\n";
}
}