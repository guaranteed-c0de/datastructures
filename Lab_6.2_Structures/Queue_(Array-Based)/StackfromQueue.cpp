#include <stdexcept>
#include <iostream>
using namespace std;
#include "ArrayQueue.h"

template <typename T>
int StackfromQueue::pop() {

    if (!Q1.IsEmpty())
        return Q1.Dequeue();
    else if (!Q2.IsEmpty())
        return Q2.Dequeue();
    else {
        throw std::underflow_error("Stack is empty, no elements can be removed.\n");
    }
}
template <typename T>
void StackfromQueue::push(T item) {
    if (Q1.IsEmpty())
    {
        Q1.Enqueue(item);
        while (!Q2.IsEmpty())
    {
       int temp = Q2.Dequeue();
       Q1.Enqueue(temp);
    }
    }
    
    else {
        Q2.Enqueue(item);
        while (!Q1.IsEmpty())
        {
            int temp = Q1.Dequeue();
            Q2.Enqueue(item);
        }
    }
}
template <typename T>
int StackfromQueue::peek() {
    if (!Q1.IsEmpty()) {
        return Q1.GetFront();
    }

    else if (!Q2.IsEmpty()) {
        return Q2.GetFront();
    }
    else if (Q2.IsEmpty() && Q1.IsEmpty()) {
         throw std::underflow_error("Stack is empty, no elements can be seen.\n");
    }
    }

