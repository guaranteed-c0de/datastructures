#ifndef STACK_H
#define STACK_H

typedef int ItemType;
struct Node {
ItemType data;
Node* next;
Node(ItemType item) : data(item), next(nullptr) {}
};
class Stack {
    private:
        Node* top;
    public:
    Stack();
    ~Stack();
       bool isEmpty();
       bool isFull();
       void push(ItemType item);
       ItemType pop();
       ItemType peek();
       void MakeEmpty();

};
#endif //STACK_H