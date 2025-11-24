#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#include <stdexcept>
struct Node {
int data;
Node* next;
Node(int val) : data(val), next(nullptr) {}
};

class Stack{
public:
    Node* top;
    int length;
    Stack() : top(nullptr), length(0) {}
    void push(int val);
    int pop();
    int peek();
    bool isEmpty();
    void Print();
    void sortStack();
    void SortHelper(int value);
};

void Stack::push(int val) {
    Node* newNode = new Node(val);
    if (isEmpty())
    {
        top = newNode;
    }
    else {
        newNode->next = top;
        top = newNode;
    }
    length++;
}
int Stack::pop() {
    if (isEmpty())
    throw std::underflow_error("List is empty.");
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    length--;
    return x;
}
bool Stack::isEmpty() {
    return top == nullptr;
}
int Stack::peek() {

    if (isEmpty())
     throw std::underflow_error("List is empty.");
    return top->data;
}
void Stack::Print() {
    if (isEmpty())
    {
        throw std::underflow_error("List is empty.");
    }
    cout << "Here is the stack:\n";
    Node* loc = top;
    while (loc)
    {
        cout << loc->data << endl;
        loc = loc->next;
    }
}
void Stack::sortStack() {
    if (isEmpty())
    {
        return;
    }
    int temp = pop();

    sortStack();
    SortHelper(temp);
}

void Stack::SortHelper(int value) {
    if (isEmpty() || top->data <= value)
    {
        push(value);
        return;
    }
    

    int temp = pop();
    SortHelper(value);

    push(temp);
}


#endif //STACK_H 