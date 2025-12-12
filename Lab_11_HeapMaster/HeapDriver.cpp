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
void scheduler(HeapMaster<Task,10005, PriorityCompare> Deadline);
int main() {
  /*  HeapMaster<int, 100005, std::greater<int>> Face;

    for (int i = 1; i <= 10; i++)
    {
        Face.push(i);
    }
    Face.printArray();

   cout << "The top of the heap is " <<  Face.top() << endl;
  

   Face.printHeap(); */
   HeapMaster<int, 1000000, std::greater<int>> TestPush;
   HeapMaster<int, 1000000, std::greater<int>> TestBuild;
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
  /* while (!SRTF.Isempty()) {
    auto task = SRTF.top(); SRTF.pop();
    cout << "Time " << time << ": Running Task " << task.id
    << " (rem=" << task.remaining_time << ")\n";

    task.remaining_time -=1;
    time++;
 
    if (task.remaining_time > 0) {
      //Put back with decreased reamining time-> higher priority!
      SRTF.push(task); //Or better: Use decreaseKey if you keep index.
    }
   } */


   HeapMaster<Task, 10005, PriorityCompare> Priority;
   HeapMaster<Task, 10005, EDFCompare> EDF;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> One(1, 100);
    std::uniform_int_distribution<> Two(1, 100);
    std::uniform_int_distribution<> Three(1, 10);
    std::uniform_int_distribution<> Four(1, 10000);
    for (int i = 1; i<= NUMBER_OF_TASKS; i++) {
    Task x;
    x.id = i;
    x.priority = One(gen);
    x.arrivalTime = Two(gen);
    x.burstTime = Three(gen);
    x.deadline = Four(gen);

    EDF.push(x);
    Priority.push(x);
   }
scheduler(Priority);
}
void scheduler(HeapMaster<Task,10005, PriorityCompare> priority)
{
    int currentTime = 0;

    struct Result {
        int id;
        int arrival;
        int start;
        int finish;
        int deadline;
        bool missed;
        int waiting;
        int turnaround;
    };

    std::vector<Result> results;

    // ready queue sorted by deadline
    HeapMaster<Task,10005,EDFCompare> ready;

    // ---------------------------
    // Main Simulation Loop
    // ---------------------------
    while (!priority.Isempty() || !ready.Isempty())
    {
        // Move all tasks that have arrived into ready queue
        while (!priority.Isempty())
        {
            Task peek = priority.top();
            if (peek.arrivalTime <= currentTime)
            {
                ready.push(peek);
                priority.pop();
            }
            else break;
        }

        // If no ready tasks, jump time to next arrival
        if (ready.Isempty())
        {
            Task nextArrival = priority.top();
            currentTime = nextArrival.arrivalTime;
            continue;
        }

        // Get earliest-deadline task
        Task current = ready.top();
        ready.pop();

        int startTime = currentTime;

        // Run task to completion (NON-PREEMPTIVE EDF)
        currentTime += current.burstTime;

        int finishTime = currentTime;

        // Save result
        Result r;
        r.id = current.id;
        r.arrival = current.arrivalTime;
        r.start = startTime;
        r.finish = finishTime;
        r.deadline = current.deadline;
        r.turnaround = finishTime - r.arrival;
        r.waiting = r.start - r.arrival;
        r.missed = (finishTime > r.deadline);

        results.push_back(r);
    }

    // ---------------------------
    // Stats
    // ---------------------------
    double avgWaiting = 0.0;
    double avgTurnaround = 0.0;
    int missedCount = 0;

    for (auto &r : results) {
        avgWaiting += r.waiting;
        avgTurnaround += r.turnaround;
        if (r.missed) missedCount++;
    }

    avgWaiting /= results.size();
    avgTurnaround /= results.size();

    // ---------------------------
    // Output
    // ---------------------------
    std::cout << "Gantt Chart (ID over time):\n";
    for (auto &r : results) {
        std::cout << "Task " << r.id 
                  << " ran from t=" << r.start 
                  << " to t=" << r.finish 
                  << " (Deadline: " << r.deadline << ")";
        if (r.missed) std::cout << "  **MISSED**";
        std::cout << "\n";
    }

    std::cout << "\n===== Priority Scheduling Results =====\n";
    std::cout << "Total tasks: " << results.size() << "\n";
    std::cout << "Average waiting time: " << avgWaiting << "\n";
    std::cout << "Average turnaround time: " << avgTurnaround << "\n";
    std::cout << "Missed deadlines: " << missedCount << "\n\n";
}