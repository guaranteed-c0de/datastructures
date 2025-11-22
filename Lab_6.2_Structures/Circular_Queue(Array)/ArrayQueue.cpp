#include "ArrayQueue.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void CircularQueue::Enqueue(int value) {
    if (IsFull())
    {
        throw std::overflow_error("List is full, no items can be added\n");
    }
    else {
        rear = (rear + 1)%MAX;
        arr[rear] = value;
        size++;
    }
}
int CircularQueue::Dequeue() {
    if (IsEmpty())
    {
        throw std::underflow_error("List is empty, no items can be removed.");
    }
    else {
        front = (front+1)%MAX;
        size--;
    }
}
int CircularQueue::GetFront() const{
    if (IsEmpty())
    {
        throw std::underflow_error("List is empty, no items can be removed.");
    }
    return arr[front];
}

bool CircularQueue::IsEmpty() const {
    return size < 0;
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
void CircularQueue::firstNegative(int parr[], int n, int k)
{
    CircularQueue CQ;
    int result[n - k + 1];

    for (int i = 0; i < k; i++)
    {
        if (parr[i] < 0)
        {
            CQ.Enqueue(i);
        }
    }
    if (!CQ.IsEmpty())
    {
        result[0] = parr[CQ.GetFront()];
    }
    else {
        result[0] = 0;
    }
    int outIndex = 1;
    for (int i = k; i<n; i++)
    {
        while (!CQ.IsEmpty() && CQ.GetFront() <= i - k)
        {
            CQ.Dequeue();
        }
        if (parr[i] < 0)
        {
            CQ.Enqueue(i);
        }
        if (!CQ.IsEmpty())
        {
            result[outIndex] = parr[CQ.GetFront()];
        }
        else {
            result[outIndex] = 0;
        }
        outIndex++;
    }
    cout << "Okay. These are the first negatives in every window of size " << k << endl;
    for (int i = 0; i < n - k + 1; i++)
    {
        cout << "Window " << i + 1 << ": " << result[i] << endl;
    }

}
int CircularQueue::CircularTour(int petrol[], int dist[], int n)
{
    CircularQueue CQ;
    int start = 0;
    int currentFuel = 0;
    int visited = 0;

    int i = 0;

    while (visited <2*n)
    {
        currentFuel += petrol[i] - dist[i];
        CQ.Enqueue(i);
        while (currentFuel < 0 && !CQ.IsEmpty())
        {
            int removedStation = CQ.Dequeue();

            start = removedStation + 1;
            currentFuel = 0;
            for (int i = CQ.front; ; i = (i + 1)%MAX )
            {
                 int j = CQ.arr[i];
                 currentFuel += petrol[j] - dist[j];

                if (i == CQ.rear)
                 break;
            }
        
        }
        if (CQ.size == n)
        {
            return start;
        }
        i = (i + 1) % n;
        visited = visited + 1;
    }
    return -1;
}
void CircularQueue:: PrintQueue() {

    if(IsEmpty()) {
        cout << "Empty Queue" << endl;
        return;
    }
    int i = front;
    for (int count = 0; count < size; count++) { //Counter will be related to the number of times we enqueue.
        cout << arr[i] << " ";
        i = (i + 1) % MAX;
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
            movedBack(x);
        }
      
    }
    void movedBack(int x) {
        Remove(x);
        Enqueue(x);
    }
    void display() {
       PrintQueue();
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