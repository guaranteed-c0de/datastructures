#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
using namespace std;
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
        void print(Node* head);
        Node* RecursivelyReverse(Node* head);
        Node* findMiddle(Node* head);
        Node* DetectMiddle(Node* head1, Node* head2);
};

void LinkedList:: insert(int val) {
    if (!head) {
        Node* newNode = new Node(val);
        head = newNode;
    }
    else {
    Node* loc = head;
    Node* prev = head;

    while (loc) {
        prev = loc;
        loc = loc->next;

    }
    Node* newNode = new Node(val);
    prev->next = newNode;

}
}
void LinkedList::print(Node* head) {
    Node* loc = head;
    cout << "Here is the list.\n";
    while (loc)
    {
        cout << loc->data << endl;
        loc = loc->next;
    }
}

Node* LinkedList::RecursivelyReverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    else {
    Node* newHead = RecursivelyReverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
    }
}

Node* LinkedList::findMiddle(Node* head) {
    return DetectMiddle(head, head);
}

Node* LinkedList::DetectMiddle(Node* slow, Node* fast) {

    if (fast == nullptr || fast->next == nullptr) {
        return slow;
    }

    return DetectMiddle(slow->next, fast->next->next);
}
#endif //LINKED_LIST_H