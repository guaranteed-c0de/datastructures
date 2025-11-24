#ifndef STACK_H
#define STACK_H

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
    bool isEmpty();
};
#endif //STACK_H 