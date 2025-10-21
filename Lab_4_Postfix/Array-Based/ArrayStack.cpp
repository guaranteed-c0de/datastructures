#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    stackArray = new int[MAX_STACK]; //Why not stackArray = nullptr;?
    top = 0;
}

Stack:: ~Stack() {
   delete [] stackArray; //Why not continuously popping the stack until it is empty?
}

bool Stack::isEmpty() {
    return top == 0;
}

bool Stack::isFull() {
    return top == MAX_STACK - 1;
}
void Stack::push(ItemType item) {
    if (!isFull())
    {
         stackArray[top] = item;
         top++;
    }
    else {
        cout << "\nThe list is full. No more items can be pushed.\n";
    }
}
int Stack::pop() {
    if(!isEmpty())
    {
        return stackArray[top--];
        
    }
    else {
         cout << "\nThe list is empty. No items can be popped.\n";
        return -999;
       
    }
}
int Stack::peek() {
    if(!isEmpty())
    {
        return stackArray[top];
    }
    else {
        return -999;
    }
}
void Stack::makeEmpty() {
    while (!isEmpty())
    {
        pop();
    }
    cout << "The stack is empty.";
}