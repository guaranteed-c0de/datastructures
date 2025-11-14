#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node {
int data;
Node* next;
Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    public:
        Node* head;
        LinkedList() : head(nullptr) {}
        void insert(int val); 
        void print();
};

void LinkedList:: insert(int val) {

}
#endif //LINKED_LIST_H