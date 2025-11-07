#include "ArrayQueue.h"
#include <iostream>
using namespace std;


void CircularQueue::Enqueue(int value) {
    if (IsFull())
    {

    }
}

bool CircularQueue::IsEmpty() const {
    return size == MAX;
}

bool CircularQueue:: Remove(int x) {
    if (IsEmpty()) {
        return false;
    }
    int temp[MAX];
    int count = 0;
    bool found = flase;

    while (!IsEmpty() && count < capacity) { //Create an LRU class? Is it derived
        int val = Dequeue()
        if (val !=x) {
            temp[count++]
        }
    }
}


class LRUCache {
    private:
    CircularQueue queue;
    static const int capacity = 100;
    static const int size = 10;

    bool present[capacity];
    public:
    LRUCache() {
        for (int i = 0; i < size; i++) {
            present[i] = false;
        }
    }
    void reference(int x) {
        if (x < 0 || x>= capacity) {
            std::cout << "Value out of range."
            return;
        }
        if (!present[x]) {
            if (queue.IsFull()) {
                int lru = queue.Dequeue();
                present[lru] = false;
            }
              queue.Enqueue(x);
        present[x] = true;

        }
        else {
            queue.movedBack(x);
        }
      
    }
}; //False...? True.... True...? Bitmap? Dequeue it from the front, put it in the back. Memory references.... Memory frames.... You don't want to run out of 