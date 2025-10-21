
#ifndef STACK_H
#define STACK_H
#include <iostream>

typedef int ItemType;
class Stack{
    private:
        Node* top;
    public:
        Stack();
        ~Stack();
        bool isEmpty(); //Returns true if the stack is empty.
        bool isFull(); //Returns true if the stack is full.
        void push(ItemType item); //Adds an item to the top of the stack. For array-based, it must first check if the stack is full. For linked lists, it always succeeds.
        ItemType pop(); //Removes and returns the top item of the stack. Returns -999 if stack is already empty.
        ItemType peek(); //Returns the top item of the stack, without removing it. Returns -999 if the stack is empty.
        void makeEmpty(); //Empties the stack.

};
struct Node {
ItemType data;
Node* next;
Node(ItemType item) : data(item), next(nullptr) {}
};
#endif //STACK_H