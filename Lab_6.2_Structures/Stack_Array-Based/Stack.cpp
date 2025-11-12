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
void Stack::nextGreater(int arr[], int n) {
    int out[n];
    Stack Kairi2;
    
    for (int i = n - 1; i>=0; i--)
    {
        if (i == n - 1)
        {
            out[i] = -1;
            Kairi2.push(arr[i]);
        }
        else {
            if (Kairi2.Peek() > arr[i])
            {
                out[i] = Kairi2.Peek();
            }
            else {
                while (!Kairi2.isEmpty())
                {
                    if (Kairi2.Peek() > arr[i])
                    {
                        out[i] = Kairi2.Peek();
                        break;
                    }
                    else {
                        Kairi2.pop();
                    }

                }
            }
        }
    }
 cout << "Here are the next greater elements:\n";
 cout<< "Original array:\n";
 for (int i = 0; i <= n - 1; i++)
 {
    cout << arr[i];
 }

 cout << endl;

 for (int i = 0; i<= n - 1; i++)
 {
    cout << out[i];
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