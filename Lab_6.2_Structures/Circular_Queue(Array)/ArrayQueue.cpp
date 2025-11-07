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
    bool found = false;

    while (!IsEmpty()) { //Create an LRU class? Is it derived
        int val = Dequeue();
        if (val !=x) {
            temp[count++];
        }
        else {
            found = true;
        }
    }
}
void PrintQueue() {

    if(IsEmpty()) {
        cout << "Empty Queue" << endl;
        return;
    }
    int i = front;
    for (int count = 0; count < Lsize; count++) { //Counter will be related to the number of times we enqueue.
        cout << data[i] << " ";
        i = (i + 1) % capacity;
    }
}

class LRUCache: public CircularQueue {
    private:
    CircularQueue queue;
    static const int capacity = 100;
    static const int Lsize = 10;

    bool present[capacity];
    public:
    LRUCache() {
        for (int i = 0; i < Lsize; i++) {
            present[i] = false;
        }
    }
    void reference(int x) {
        if (x < 0 || x>= capacity) {
            std::cout << "Value out of range.";
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
    void movedBack(int x) {
        Remove(x);
        Enqueue(x);
    }
    void display() {
        queue.PrintQueue();
        cout << endl;
    }

}; //False...? True.... True...? Bitmap? Dequeue it from the front, put it in the back. Memory references.... Memory frames.... You don't want to run out of 

int main() {
    LRUCache lc;
lc.reference(1); //First 3 are cache.... "misses"? They weren't used before. They weren't IN the cache before.
lc.reference(2); //Made a reference to 1. What does that even mean?
lc.reference(3);
lc.reference(1); //Not a cache miss. 
lc.reference(4);
lc.reference(5);
lc.display(); //Expected output: 2 3 1 4 5

lc.reference(2);
lc.display(); //Expected output: 3 1 4 5 2

for (int i = 6; i<=12; i++) {
    lc.reference(i);
    if (i == 13)
    {
        lc.display(); //Powers... service..... //Update cache... Top 1000 people..? The number was not in the cache.
    }
}
return 0;
} //Memory is limited. Page frames... They go into the hard drive... It has more space, and isn't as expensive. If the references is in one of these pages.... Engaged with memory. The speed of memory is slower...

//Add it in the back. Move up the front.