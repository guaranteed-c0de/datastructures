#include "HeapMaster.h"
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>
struct SRTFTask {
  int id;
  int remaining_time;
  int arrival_time;
  bool operator<(const SRTFTask& other) const {
  return remaining_time < other.remaining_time; //min-heap
}
};
int main() {
  /*  HeapMaster<int, 100005, std::greater<int>> Face;

    for (int i = 1; i <= 10; i++)
    {
        Face.push(i);
    }
    Face.printArray();

   cout << "The top of the heap is " <<  Face.top() << endl;
  

   Face.printHeap(); */
   HeapMaster<SRTFTask, 1000, std::less<SRTFTask>> SRTF;

   //Insert tasks
   SRTF.push({1, 10, 0});
   SRTF.push({2, 3, 1});
   SRTF.push({3, 5, 2});

   //Simulate time
   int time = 0;
   while (!SRTF.Isempty()) {
    auto task = SRTF.top(); SRTF.pop();
    cout << "Time " << time << ": Running Task " << task.id
    << " (rem=" << task.remaining_time << ")\n";

    task.remaining_time -=1;
    time++;

    if (task.remaining_time > 0) {
      //Put back with decreased reamining time-> higher priority!
      SRTF.push(task); //Or better: Use decreaseKey if you keep index.
    }
   }


  /* HeapMaster<Task, 10005, TaskCompare> Priority;
   HeapMaster<Task, 10005, TaskCompare2> Deadline;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> One(1, 100);
    std::uniform_int_distribution<> Two(1, 80);
    std::uniform_int_distribution<> Three(1, 60);
    std::uniform_int_distribution<> Four(1, 40);
   for (int i = 1; i<= 100; i++) {
    Task x;
    x.id = i;
    x.priority = One(gen);
    x.arrivalTime = Two(gen);
    x.burstTime = Three(gen);
    x.deadline = Four(gen);

    Deadline.push(x);
   }
   cout << "This is the heap, in priority.\n";
for (int i = 0; i<Deadline.Getsize(); i++)
{
    Deadline.top().print();
    Deadline.pop();
    cout << "\n";
} */
}