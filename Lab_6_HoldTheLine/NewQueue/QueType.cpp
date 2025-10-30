#include "QueType.h"

QueType::QueType(int max) {
    maxQue = max;
    front = max - 1;
    rear = max - 1;
    length = 0;
}

QueType::QueType() {
    maxQue = 100;
    front = 100 - 1;
    rear = 100 - 1;
    length = 0;
}

QueType::~QueType()
{
    length = 0;
    rear = front;
}

void QueType::MakeEmpty()
{
    length = 0;
    rear = front;
}

bool QueType::IsEmpty() const
{
    return length == 0 && rear == front;
} 
bool QueType::IsFull() const
{
    return length == maxQue;
}
void QueType::Enqueue(ItemType newItem) {
    rear = (rear + 1)% maxQue;
    items[rear] = newItem;
    length++;
}
void QueType::Dequeue(ItemType &item)
{
front = (front + 1)% maxQue;
length--;
}