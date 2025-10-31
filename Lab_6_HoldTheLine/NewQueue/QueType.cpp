#include "QueType.h"

QueType::QueType(int max) {
    maxQue = max;
    front = max - 1;
    rear = max - 1;
    length = 0;
}

QueType::QueType() {
    maxQue = 100;
    front = 0;
    rear = 0;
    length = 0;
}

QueType::~QueType()
{
    delete [] items;
}

void QueType::MakeEmpty()
{
    length = 0;
    rear = front;
}

bool QueType::IsEmpty() const
{
    return length == 0;
} 
bool QueType::IsFull() const
{
    return length == maxQue;
}
void QueType::Enqueue(ItemType newItem) {
    if (IsFull())
    {
        throw FullQueue();
    }
    else {
    rear = (rear + 1)% maxQue;
    items[rear] = newItem;
    length++;
    }
}
void QueType::Dequeue(ItemType &item)
{
    if (IsEmpty) {
        throw EmptyQueue();
    }
    else {
front = (front + 1)% maxQue;
length--;
}
}
int QueType::GetLength() {
    
    return length;
}