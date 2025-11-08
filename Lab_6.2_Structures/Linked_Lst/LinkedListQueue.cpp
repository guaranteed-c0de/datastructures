#include "LinkedListQueue.h"
#include "stdexcept"
#include <iostream>
using namespace std;

// LinkedListQueue:: LinkedListQueue() {
// front = nullptr;
// rear = nullptr;
// }

void LinkedListQueue::Enqueue(int x)
{
    QNode* newNode = new QNode(x);
    if (IsEmpty())
{
    rear = newNode;
    newNode->next = nullptr;
}
   else {
   newNode->next = front;
   front = newNode;
   }

   length++;
}

int LinkedListQueue::Dequeue() {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty. No node can be removed.");
    }
    QNode* loc = front;
    QNode* prev = nullptr;
    while (loc != rear)
    {
        prev = loc;
        loc = loc->next;
    }
   rear = prev;
   int dequeued = loc->val;
   delete loc;
   length--;
   return dequeued;
}

int LinkedListQueue::GetFront() {
return rear->val;
}

bool LinkedListQueue::IsEmpty() const{
    return front == nullptr;
}

LinkedListQueue::~LinkedListQueue() {
    QNode* loc = front;
    while (loc != nullptr)
    {
        QNode* temp = loc;
        loc = loc->next;
        delete temp;

    }
}
void LinkedListQueue:: Reverse(LinkedListQueue& queue) {
    Print(queue);
    int arr[queue.length];
   QNode* loc = queue.front;
   int i = 0;
    while (loc != nullptr)
    {
    arr[i] = queue.Dequeue();
    }
    int j = queue.length - 1;

    while (j >=0)
    {
        queue.Enqueue(arr[j]);
        j--;
    }
}

void LinkedListQueue::Print(LinkedListQueue& queue) const {
    QNode* loc = front;
    cout << "\nHere is the current linked list.\n";

    while (loc != nullptr)
    {
        cout << loc->val << endl;
        loc = loc->next;
    }
}
LinkedListQueue LinkedListQueue::Merge(LinkedListQueue a, LinkedListQueue b) {
LinkedListQueue c;

aloc = a
}