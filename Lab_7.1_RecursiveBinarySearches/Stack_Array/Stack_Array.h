#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include <iostream>
#include <stdexcept>
    const int MAX_ITEMS = 50;

class Stack {
private:
    int Stack_arr[MAX_ITEMS];
    int top;
public:
    void push(int x);
    int pop();
    int peek();
    void Print();
    Stack();
    void SortStack();
    bool IsEmpty();
    bool IsFull();
    void sortedInsert(int value);
};
Stack::Stack() {
    top = -1;
}
void Stack::push(int x) {
    if (IsFull())
    {
        throw std::overflow_error("The stack is full.");
    }
    top++;
    Stack_arr[top] = x;
}
int Stack::pop() {
      if (IsEmpty())
    {
        throw std::underflow_error("List is empty.\n");
    }
    int value = Stack_arr[top];
    top--;
    return value;
}

int Stack::peek() {
    if (IsEmpty())
    {
        throw std::underflow_error("List is empty.\n");
    }
    return Stack_arr[top];
}
bool Stack::IsEmpty() {
    return top < 0;
}
bool Stack::IsFull() {
    return top >= MAX_ITEMS - 1;
}
void Stack::SortStack() {
    if (IsEmpty()) {
        return;
    }
  int current_top_of_stack = peek();
  pop();
  SortStack();
  sortedInsert(current_top_of_stack);  
}
void Stack::sortedInsert(int value) {
    if(IsEmpty() || value >= peek()) 
    {
        push(value); //This is the base case of insertion.
        return;
    }
    int temp = peek();
    pop();
    sortedInsert(value);
    push(temp);
}
void Stack::Print() {
    if (IsEmpty())
    {
        throw std::underflow_error("List is empty.\n");
    }
    std::cout << "This is the list.\n";
      Stack Yozora;
    Stack Noctis;
    while (!IsEmpty())
{
 Yozora.push(pop());
}
   while (!Yozora.IsEmpty()) {
    Noctis.push(Yozora.peek());
    push(Yozora.pop());
   }
   while (!Noctis.IsEmpty()) {
    std::cout << Noctis.pop() << std::endl;
   }
}
#endif //STACK_ARRAY_H
