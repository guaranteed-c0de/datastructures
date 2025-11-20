#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
public:
    Node* front;
    Node* rear;
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int val);
    int dequeue();
    bool isEmpty();
    void reverseQueue();
    int GetLength();
    Node* interleaveQueue(Queue& q);
     

};
int Queue::GetLength() {
    Node* loc = rear;
    int length = 0;
    while (loc)
    {
        loc = loc->next;
        length++;
    }
    return length;
}
void Queue::enqueue(int val) {
     Node* newNode = new Node(val);
    if (!front && !rear){
        front = newNode;
        rear = newNode;
    }
   else {
    rear->next = newNode;
    rear = newNode;
   }
}

int Queue::dequeue() {
    int value = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    delete temp;
    return value;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::reverseQueue() {
    if (front == nullptr || front == rear)
    {
        return;
    }
    int temp = dequeue();
    reverseQueue();

    enqueue(temp);
} //O(n) time complexity... //Comment.
Node* Queue::interleaveQueue(Queue& Q) {
    if (Q.isEmpty())
    {
        return nullptr;
    }
    int Nnodes = Q.GetLength();
    if (Nnodes%2 != 0)
    {
        cout << "Invalid queue. There must be an even number of elements.";
        return nullptr;
    }
    Queue temp;

    for (int i = 1; i <= Nnodes/2; i++)
    {
        temp.enqueue(Q.dequeue());
    }
    interleaveHelper(temp, Q);
    return Q.rear;
}

void interleaveHelper(Queue FirstHalf, Queue SecondHalf)
{
    if (FirstHalf.isEmpty())
    {
        return;
    }
   int a = FirstHalf.dequeue();
   int b = SecondHalf.dequeue();

   interleaveHelper(FirstHalf, SecondHalf);

   SecondHalf.enqueue(a);
   SecondHalf.enqueue(b);
}


#endif //QUEUE_H