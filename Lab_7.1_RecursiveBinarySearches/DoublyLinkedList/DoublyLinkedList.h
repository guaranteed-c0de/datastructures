#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

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
        void print();
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
}
}

#endif //DOUBLYLINKEDLIST_H