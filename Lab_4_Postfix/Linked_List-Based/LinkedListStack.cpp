#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(){
    top = nullptr;
}

Stack:: ~Stack() {
    while(top)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
void Stack::push(ItemType item) {
    Node* newNode = new Node(item);
    newNode->next = top;
    top = newNode;

}
ItemType Stack::pop() {
    if (top)
    {
        ItemType item = top -> data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return item;
    }
    else {
    cout << "The list is empty.\n";
    return -999;
    }
}
ItemType Stack:: peek() {
    if (top){
        return top->data;
    }
    else {
        cout << "The list is empty.\n";
        return -999;
    }
}
bool Stack:: isEmpty() {
    return top == nullptr;
}
bool Stack::isFull() {
    cout << "This linked list cannot be filled.\n";
    return false;
}
void Stack::makeEmpty() {
    while(top)
      {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

}
