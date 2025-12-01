#include "HeapMaster.h"
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <algorithm>
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
  const int NUMBER_OF_TASKS = 1000;
int PriorityarrivalTime[NUMBER_OF_TASKS];
int PriorityburstTime[NUMBER_OF_TASKS];
int Prioritydeadline[NUMBER_OF_TASKS];     
int Prioritypriority[NUMBER_OF_TASKS];     
bool Prioritydone[NUMBER_OF_TASKS];
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


   HeapMaster<Task, 10005, TaskCompare> Priority;
   HeapMaster<Task, 10005, TaskCompare2> Deadline;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> One(1, 100);
    std::uniform_int_distribution<> Two(1, 80);
    std::uniform_int_distribution<> Three(1, 60);
    std::uniform_int_distribution<> Four(1, 40);
   for (int i = 1; i<= NUMBER_OF_TASKS; i++) {
    Task x;
    x.id = i;
    x.priority = One(gen);
    x.arrivalTime = Two(gen);
    x.burstTime = Three(gen);
    x.deadline = Four(gen);

    Deadline.push(x);
    Priority.push(x);
   }
for (int i = 0; i < NUMBER_OF_TASKS; i++) {
PriorityarrivalTime[i] = Priority.top().arrivalTime;
PriorityburstTime[i] = Priority.top().burstTime;
Prioritydeadline[i] = Priority.top().deadline;
Prioritypriority[i] = Priority.top().priority;
Prioritydone[i] = false;
Priority.pop();
}

}
void runFixedPriority(std::vector<Task> tasks) {
    int n = (int)tasks.size();
    std::vector<bool> done(n, false);
    int finished = 0;
    int currentTime = 0;

    long long totalWait = 0;
    long long totalTurnaround = 0;
    int missedDeadlines = 0;

    while (finished < n) {
        // find best task among arrived tasks (higher priority value = better)
        int next = -1;
        int bestPriority = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (done[i]) continue;
            if (tasks[i].arrivalTime <= currentTime) {
                if (tasks[i].priority > bestPriority) {
                    bestPriority = tasks[i].priority;
                    next = i;
                }
            }
        }

        // if none available, jump to next arrival
        if (next == -1) {
            int soonest = INT_MAX;
            for (int i = 0; i < n; ++i) if (!done[i] && tasks[i].arrivalTime < soonest) soonest = tasks[i].arrivalTime;
            currentTime = soonest;
            continue;
        }

        // schedule next
        int startTime = currentTime;
        int finishTime = startTime + tasks[next].burstTime;
        int waitTime = startTime - tasks[next].arrivalTime;
        int turnaround = finishTime - tasks[next].arrivalTime;

        totalWait += waitTime;
        totalTurnaround += turnaround;
        if (finishTime > tasks[next].deadline) ++missedDeadlines;

        // advance time and mark done
        currentTime = finishTime;
        done[next] = true;
        ++finished;
    }

    std::cout << "Fixed Priority results: \n";
    std::cout << "Missed deadlines: " << missedDeadlines << "\n";
    std::cout << "Average wait: " << (double)totalWait / n << "\n";
    std::cout << "Average turnaround: " << (double)totalTurnaround / n << "\n";
}
