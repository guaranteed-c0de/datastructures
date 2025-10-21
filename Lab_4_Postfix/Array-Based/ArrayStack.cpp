#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
   int* stackArray = new int[MAX_STACK]; //Why not stackArray = nullptr;?
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
        top++; stackArray[top] = item;
    }
    else {
        cout << "\nThe list is full. No more items can be pushed.\n";
    }
}
int Stack::pop() {
    if(!isEmpty())
    {
        return stackArray[top];
        top--;
    }
    else {
        return -999;
        cout << "\nThe list is empty. No items can be popped.\n"
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