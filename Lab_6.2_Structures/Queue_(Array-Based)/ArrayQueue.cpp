#include "ArrayQueue.h"
#include <stdexcept>
template <typename T>
void Queue<T>:: Enqueue(T x) {
    if (IsFull())
    {
        throw std::overflow_error("The queue is full.\n");
    }
    else {
        rear++;
        arr[rear] = x;
    }


}
template <typename T>
T Queue <T>::Dequeue() {
    if (IsEmpty())
    {
        throw std::underflow_error("The queue is empty.");
    }
   int result = arr[front];
   front++;
   return result;
}
template <typename T>

T Queue<T>::GetFront() const{
return arr[front];
}
template <typename T>
bool Queue<T>::IsEmpty() const {
    return front > rear;
}

template <typename T>
bool Queue<T>::IsFull() const {
    return rear == MAX - 1;
}
template <typename T>
void Queue<T>:: ReverseK(Queue& q, int k) const{
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
/*void Queue::generateBinary(int n) {
    Queue M;

    M.Enqueue("1");

    for (int i = 1; i<= n; i++)
    {
        int top = M.Dequeue();
        cout << top << endl;
        int binary1 = front + "0";
        int binary2 = top + "1";

        M.Enqueue(binary1);
        M.Enqueue(binary2);
    } 
}*/