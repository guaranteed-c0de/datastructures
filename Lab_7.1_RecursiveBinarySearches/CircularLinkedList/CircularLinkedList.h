#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    public:
        CNode* head;
        CircularLinkedList() : head(nullptr){}
        void insert(int val);
        void print(CNode* head);
};

void CircularLinkedList::insert(int val) {
    CNode* newNode = new CNode(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else {
        CNode* loc = head;
        while(loc->next) {
            loc = loc->next;
        }
        loc->next = newNode;
    }
    newNode->next = head;
}

void CircularLinkedList::print(CNode* head) {
    if (head == nullptr)
    {
        cout << "There are no nodes to print.\n";
        return;
    }
    CNode* loc = head;

    do {
       cout << loc->data << endl;
       loc = loc->next;
    } while (loc != head);
}
#endif //CIRCULAR_LINKED_LIST_H