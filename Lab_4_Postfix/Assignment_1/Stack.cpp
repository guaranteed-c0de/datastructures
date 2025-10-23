#include "Stack.h"

Stack::Stack(){
    top = nullptr;
}
Stack:: ~Stack() 
{  
while(top)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::isEmpty() {
    return top == nullptr;
}
bool Stack::isFull() {
    return false;
}
void Stack::push(ItemType item) {
    Node* newNode = new Node(item); 
    newNode -> next = top; 
    top = newNode;
}
ItemType Stack::pop() {
    if (!isEmpty())
 {   Node* temp = top;
    ItemType item = temp->data;
    top = top->next;
    delete temp;
    return item;}
    else {
        return -999;
    }
}

ItemType Stack::peek() {
    if (top)
    {
        return top->data;
    }
    else {
        return -999;
    }
}

void Stack::MakeEmpty() {
    while (top) {
        pop();
    }
}

