#ifndef HEAPMASTER_H
#define HEAPMASTER_H

#include <iostream>
#include <iomanip>
#include <cstring>

struct Task {
    int id;
    int priority;
    int arrivalTime;
    int burstTime;
    int deadline;

    void print() const {
        std::cout << "Task# " << id << std::endl;
        std::cout << "priority: " << priority << std::endl;
        std::cout << "Arrival Time: " << arrivalTime << std::endl;
        std::cout << "Burst Time: " << burstTime << std::endl;
        std::cout << "Deadline: " << deadline << std::endl;
      
    }
};

template <typename T, int MAX_SIZE = 100005, typename Compare = std::less<T>>
class HeapMaster {
    private:
        T data[MAX_SIZE];
        int current_size;
        Compare comparator; //Less = max-heap, greater = min-heap.
        int parent(int i) const {return (i - 1)/2;}
        int left(int i) const {return 2*i + 1;}
        int right(int i) const {return 2*i + 2;}

        void heapifyUp(int i);
        void heapifyDown(int i);
    
    public:
        HeapMaster() : current_size(0) {}

        bool Isempty() const {return current_size = 0;}
        int Getsize() const {return current_size;}
        const T& top() const;

        void push(const T& val);
        void pop();
        void clear() {current_size = 0;}

        bool decreaseKey(int index, const T& newVal);
        bool increaseKey(int index, const T& newVal);
        void printHeap() const;
        void printArray() const;
};
#include "HeapMaster.cpp"
#endif //HEAPMASTER_H