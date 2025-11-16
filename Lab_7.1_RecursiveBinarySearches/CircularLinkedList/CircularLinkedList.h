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
        int CalculateCycle(CNode* head);
        int LengthHelper(CNode* node, CNode* head);
        void SortedInsert(int val);
        void InsertHelper(CNode* node, int val);
        void DeleteNode(CNode* node);
        void DeleteHelper(CNode* node);
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
int CircularLinkedList:: CalculateCycle(CNode* head) {
    int length;
    if (head == nullptr)
    {
        return 0;
    }

    return LengthHelper(head, head);
}

int CircularLinkedList:: LengthHelper(CNode* node, CNode* head) {

    if (node->next == head) {
        return 1;
    }
    else {
        return 1 + LengthHelper(node->next, head);
    }
}

void CircularLinkedList:: SortedInsert(int val) {
    if (head == nullptr) {
        CNode* newNode = new CNode(val);
        head = newNode;
        newNode->next = head;
    }
    else {
        InsertHelper(head, val);
    }
}

void CircularLinkedList::InsertHelper(CNode* node, int val) {
    if (node->next->data < val)
    {
        CNode* newNode = new CNode(val);
        newNode->next = node;
        node = newNode;
        
    }
    else if (node->next == head) {
        CNode* newNode = new CNode(val);
        newNode->next = head;
        node = newNode;
    }
    else {
        InsertHelper(node->next, val);
    }
}
void CircularLinkedList:: DeleteNode(CNode* node) {
    if (head == nullptr)
    {
        return;
    }

    else {
        node = node->next;
    }
}
#endif //CIRCULAR_LINKED_LIST_H