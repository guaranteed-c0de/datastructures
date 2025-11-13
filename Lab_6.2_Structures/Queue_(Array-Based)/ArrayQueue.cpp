#include "ArrayQueue.h"
#include <stdexcept>
void Queue::Enqueue(string x) {
    if (IsFull())
    {
        throw std::overflow_error("The queue is full.\n");
    }
    else {
        rear++;
        arr[rear] = x;
    }


}
string Queue::Dequeue() {
    if (IsEmpty())
    {
        throw std::underflow_error("The queue is empty.");
    }
   string result = arr[front];
   front++;
   return result;
}

string Queue::GetFront() const{
return arr[front];
}

bool Queue::IsEmpty() const {
    return front > rear;
}

bool Queue::IsFull() const {
    return rear == MAX - 1;
}

/*void Queue:: ReverseK(Queue& q, int k) const{
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
}  */
void Queue::generateBinary(int n) {
    Queue M;

    M.Enqueue("1");

    for (int i = 1; i<= n; i++)
    {
        string top = M.Dequeue();
        cout << top << endl;
        string binary1 = front + "0";
        string binary2 = top + "1";

        M.Enqueue(binary1);
        M.Enqueue(binary2);
    }
}