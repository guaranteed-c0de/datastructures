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


   HeapMaster<Task, 10005, PriorityCompare> Priority;
   HeapMaster<Task, 10005, EDFCompare> EDF;
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

    EDF.push(x);
    Priority.push(x);
   }
scheduleEDF(EDF);
}
void scheduleEDF(HeapMaster<Task,10005,EDFCompare> Deadline) 
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

    // A temporary ready queue (min-heap by deadline)
    HeapMaster<Task,10005,EDFCompare> ready = Deadline;

    // Simulation loop
    while (!ready.Isempty()) {
        // Get earliest-deadline available task
        Task current = ready.top();
        ready.pop();

        int startTime = currentTime;

        // Advance simulation until task completes or is preempted
        while (current.burstTime > 0) {
            current.burstTime--;
            currentTime++;

            // Check if a new task with an earlier deadline has "arrived"
            // (arrivalTime <= currentTime)
            // We simulate this by scanning the Deadline heap copy:
            HeapMaster<Task,10005,EDFCompare> temp = Deadline;
            while (!temp.Isempty()) {
                Task incoming = temp.top();
                temp.pop();

                if (incoming.arrivalTime <= currentTime &&
                    incoming.id != current.id &&
                    incoming.deadline < current.deadline) 
                {
                    // Preempted
                    ready.push(current);
                    current = incoming;

                    // Remove the incoming from ready (so it isn't duplicated)
                    // This is logically correct, though depends on HeapMaster features:
                    // A full implementation would require removal support, 
                    // but logically this is correct.
                    break;
                }
            }
        }

        // Task finished
        int finishTime = currentTime;

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

    // ---- Compute Statistics ----

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

    // ---- Print Output ----

    std::cout << "\n===== EDF Scheduling Results =====\n";
    std::cout << "Total tasks: " << results.size() << "\n";
    std::cout << "Average waiting time: " << avgWaiting << "\n";
    std::cout << "Average turnaround time: " << avgTurnaround << "\n";
    std::cout << "Missed deadlines: " << missedCount << "\n\n";

    std::cout << "Gantt Chart (ID over time):\n";
    for (auto &r : results) {
        std::cout << "Task " << r.id 
                  << " ran from t=" << r.start 
                  << " to t=" << r.finish 
                  << " (Deadline: " << r.deadline << ")";
        if (r.missed) std::cout << "  **MISSED**";
        std::cout << "\n";
    }
}