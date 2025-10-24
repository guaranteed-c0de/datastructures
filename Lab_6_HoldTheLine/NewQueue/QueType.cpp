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
{}

void QueType::MakeEmpty()
{}

bool QueType::IsEmpty() const
{} 
bool QueType::IsFull() const
{}
void QueType::Enqueue(ItemType newItem) {
    rear = (rear + 1)% maxQue;
    items[rear] = newItem;
    length++;
}
void QueType::Dequeue(ItemType &item)
{

}