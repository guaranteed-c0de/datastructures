#include "ArrayQueue.h"
#include <stdexcept>
void Queue::Enqueue(int x) {
    if (IsFull())
    {
        throw std::overflow_error("The queue is full.");
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

void 