#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
    public:
        DNode* head;
        DoublyLinkedList() : head(nullptr) {}
        void insert(int val);
        void print(DNode* head);
        void RecursivelyReverse(DNode* head);
};

void DoublyLinkedList:: insert(int val) {
DNode* newNode = new DNode(val);
    if (!head)
{
    head = newNode;
}
else {
    DNode* loc = head;
    DNode* last = head;
    while (loc)
    {
       last = loc;
       loc = loc->next;
    }
    last->next = newNode;
    newNode->prev = last;

}
}
void DoublyLinkedList::print(DNode* head) {
    DNode* loc = head;

    while (loc)
    {
        cout << loc->data << endl;
        loc = loc->next;
    }
}
void DoublyLinkedList::RecursivelyReverse(DNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
}
#endif //DOUBLYLINKEDLIST_H