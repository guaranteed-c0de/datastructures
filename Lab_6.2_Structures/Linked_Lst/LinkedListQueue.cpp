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
    front = newNode;
    newNode->next = nullptr;
}
   else {
   newNode->next = rear;
   rear = newNode;
   }

   length++;
}

int LinkedListQueue::Dequeue() {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty. No node can be removed.");
    }
    QNode* temp = front;
    QNode* loc = rear;
    QNode* prev = nullptr;
    while (loc != front)
    {
        prev = loc;
        loc = loc->next;
    }
   int dequeued = front->val;
   front = prev;
   prev->next = nullptr;
   delete temp;
   length--;
   return dequeued;
}

int LinkedListQueue::GetFront() {
return front->val;
}
int LinkedListQueue::GetLength() {
    return length;
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

QNode* aloc = a.front;
QNode* bloc = b.front;

    while (aloc && bloc) {
        if (aloc->val <= bloc->val)
        {
            c.Enqueue(aloc->val);
           aloc = aloc->next;
        }
        else {
            c.Enqueue(bloc->val);
            bloc = bloc->next;
        }
    }
    if (aloc)
    {
        while (aloc)
        {
            c.Enqueue(aloc->val);
            aloc = aloc->next;
        }

    }
    else {
         while (bloc)
        {
            c.Enqueue(bloc->val);
            bloc = bloc->next;
        }
    }
    Print(c);
}

void LinkedListQueue::RemoveDuplicates(LinkedListQueue& q) {
    //Keep front and tail fixed.
    int fixed_front = q.GetFront(); //First, it has to find those duplicates... 
    QNode* loc = q.front;
    int arr[q.length];
     bool duplicate = true;
    int i = 0;
    while (loc != nullptr)
    {
        arr[i] = q.Dequeue();
    } //Only Enqueue if it isn't a duplicate...

    for (int i = 0; i<q.length;i++)
    {
     for (int j = 0; j <i; j++)   
     {
       
        if (arr[i] != arr[j])
        {
             duplicate = false;
        }
        if (!duplicate)
        {
            q.Enqueue(arr[i]);
        }
     }
    }
}
//And through these, it didn't match the parameter list.

int LinkedListQueue::Middle() {
    if (IsEmpty())
    {
        throw std::underflow_error("List is empty.");
    }
    if (GetLength() == 1)
    {
        return rear->val;
    }
int middle_place = GetLength()/2;
QNode* loc = rear;
for (int i = 1; i < middle_place; i++)
{
    loc = loc->next;
}
return loc->val;

}

void LinkedListQueue::RotateK(int k) {
if (GetLength() == 0)
{
    throw std::underflow_error("List is empty.\n");
}
if (GetLength() == 1) {
    return;
}
if (k > GetLength() - 1) {
    throw std::out_of_range("The queue does not have enough elements.\n");
}
int moves = (GetLength() - k)- 2;
QNode* loc = rear;
int value = Dequeue();
for (int i = 1; i<= moves; i++)
{
    loc = loc->next;
}
QNode* newNode = new QNode(value);
newNode->next = loc->next;
loc->next = newNode;
length++;
}

void StackFromLinkedListQueue::push(int x) {
    q.Enqueue(x);

    for (int i = 1; i < q.GetLength(); i++)
    {
        int temp = q.Dequeue();
        q.Enqueue(temp);
    }
}

int StackFromLinkedListQueue::pop() {
    if (q.IsEmpty())
    {
        throw std::underflow_error("The queue is empty. No element can be removed.");
    }

    return q.Dequeue();
}

int StackFromLinkedListQueue::peek() {
    if (q.IsEmpty())
    {
        throw std::underflow_error("The queue is empty. No element can be seen.");
    }

    return q.GetFront();
}

