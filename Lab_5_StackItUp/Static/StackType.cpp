// File: StackType.cpp

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

void StackType::SetSecondElement(ItemType item) {
    Pop();
    Pop();
    ItemType second_element = item;
    Push(second_element);
}
ItemType StackType::SetBottomWithStackEmpty() {
    ItemType bottom;
    
    while (!IsEmpty())
    {
    bottom = Top();
       Pop(); 
    }
    return bottom;


}
ItemType StackType::SetBottomeWithoutStackEmpty() {
    ItemType bottom;
    StackType tempStack;
    while (!IsEmpty()) {
        tempStack.Push(Top());
        bottom = Top();
        Pop();
    }
    while (!tempStack.IsEmpty())
    {
        Push(tempStack.Top());
        tempStack.Pop();
    }
    return bottom;
}
void StackType::CopyStackMaintainStack() {
StackType stack2;
StackType temp;
    while (!IsEmpty()) {
        temp.Push(Top());
        Pop();
    }
    while (!temp.IsEmpty()) {
        Push(temp.Top());
        stack2.Push(temp.Top());
        temp.Pop();
    }
}
