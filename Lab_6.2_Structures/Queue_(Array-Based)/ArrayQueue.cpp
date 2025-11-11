#include "ArrayQueue.h"
#include <stdexcept>
void Queue::Enqueue(int x) {
    if (IsFull())
    {
        throw std::overflow_error("The queue is full.\n");
    }
    else {
        rear++;
        arr[rear] = x;
    }


}
int Queue::Dequeue() {
    if (IsEmpty())
    {
        throw std::underflow_error("The queue is empty.");
    }
   int result = arr[front];
   front++;
   return result;
}

int Queue::GetFront() const{
return arr[front];
}

bool Queue::IsEmpty() const {
    return front > rear;
}

bool Queue::IsFull() const {
    return rear == MAX - 1;
}

void Queue:: ReverseK(Queue& q, int k) const{
    if (k >= MAX)
    {
        throw std::out_of_range("The queue does not have that many elements.\n");
    }
    else {
        int reverse[k];
        
        for (int i = 0; i < k; i++)
        {
            reverse[i] = q.Dequeue();
        }
        q.front = 0;

        for (int i = 0; i < k; i++)
        {
            q.Enqueue(reverse[i]);
        }
    }
}