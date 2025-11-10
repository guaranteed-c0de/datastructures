#include "Stack.h"
#include <iostream>
using namespace std;
#include <stdexcept>
Stack::Stack() {
    top = -1;
}

void Stack::push(int x) {
    if (isFull())
    {
        throw std::overflow_error("The stack is full. No element can be pushed.\n");
    }
    else {
        top++;
        arr[top] = x;
    }
}
int Stack::pop() {
    if (isEmpty())
{
    throw std::underflow_error("The stack is empty. There is no element at the top.\n");
}
else 
{
    return arr[top--];
}
}
int Stack::Peek() const {
if (isEmpty())
{
    throw std::underflow_error("The stack is empty. There is no element at the top.\n");
}
else {
    return arr[top];
}
} 
bool Stack::isEmpty() const {
    return top < 0;
}
bool Stack::isFull() const {
    return top == MAX - 1;
}
void Stack::nextGreater() {
    int out[top];
    for (int i = top; i > 0; i--)
    {
        if (i == top)
        {
            out[i] = -1;
        }
        else {
            
        }
    }
}
void Stack::Print() {
    cout << "This is currently the stack. (Top to bottom.)\n";
    Stack Namine;
    Stack Xikira;
    while (!isEmpty())
{
 Namine.push(pop());
}
   while (!Namine.isEmpty()) {
    Xikira.push(Namine.Peek());
    push(Namine.pop());
   }
   while (!Xikira.isEmpty()) {
    cout << Xikira.pop() << endl;
   }
}