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
};

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
} //O(n) time complexity...
#endif //QUEUE_H