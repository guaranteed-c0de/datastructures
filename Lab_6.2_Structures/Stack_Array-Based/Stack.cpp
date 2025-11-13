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
        while (!Kairi2.isEmpty() && Kairi2.Peek() <= arr[i]) {
            Kairi2.pop();
        }

        
        if (Kairi2.isEmpty()) {
            out[i] = -1;
        } else {
            out[i] = Kairi2.Peek();
        }

       
        Kairi2.push(arr[i]);
    }
 cout << "Here are the next greater elements:\n";
 cout<< "Original array:\n";
 for (int i = 0; i <= n - 1; i++)
 {
    cout << arr[i] << " ";
 }

 cout << endl;

 for (int i = 0; i<= n - 1; i++)
 {
    cout << out[i] << " ";
 }
}

bool Stack::Balanced(char arr[], int n) {
Stack X;
    if (n%2 == 1) return false;

    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] == ')' || arr[i] == '}' || arr[i] == ']' || arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            if (X.isEmpty())
            {
                if(arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
                {
                    return false;
                }
                else if (arr[i] == '(') {X.push(1);}
                else if (arr[i] == '{') {X.push(3);}
                else if (arr[i] == '[') {X.push(5);}
            }
            else {
            if (arr[i] == '(')
            {
                if(X.Peek()%2 == 1) {return false;}
                else {X.push(1);}
            }
            else if (arr[i] == ')') {
                if (X.Peek() !=1) {return false;}
                else {X.push(2);}
            }
             if (arr[i] == '{')
            {
                if(X.Peek()%2 == 1) {return false;}
                else {X.push(3);}
            }
            else if (arr[i] == '}') {
                if (X.Peek() !=1) {return false;}
                else {X.push(4);}
            }
             if (arr[i] == '[')
            {
                if(X.Peek()%2 == 1) {return false;}
                else {X.push(5);}
            }
            else if (arr[i] == '}') {
                if (X.Peek() !=1) {return false;}
                else {X.push(6);}
            }
        }
        }
        else {
            return false;
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