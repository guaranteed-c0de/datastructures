#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <utility>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode* child;
    DNode(int val) : data(val), next(nullptr), prev(nullptr), child(nullptr) {}
};

class DoublyLinkedList{
    public:
        DNode* head;
        DoublyLinkedList() : head(nullptr) {}
        void insert(int val);
        void print(DNode* head);
        DNode* RecursivelyReverse(DNode* head);
        DNode* sortedInsert(DNode* head, int value);
        DNode* DeletebyValue(DNode* head, int value);
        pair <int, int> FindPair(DNode* head, int target);
        pair <int, int> FindPairHelper(DNode*, DNode*, int);
        DNode* Flatten(DNode* head);
        DNode* RotatebyK(DNode* head, int k);
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
DNode* DoublyLinkedList::RecursivelyReverse(DNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    DNode* newHead = RecursivelyReverse(head->next);

    head->next->next = head;
    head->prev = head->next;
    head->next = nullptr;

    return newHead;
}
DNode* DoublyLinkedList:: sortedInsert(DNode* head, int value) {
    DNode* newNode = new DNode(value);
    if (head == nullptr)
    {
        return = newNode;
    }

    if (value <= head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    DNode* result = sortedInsert(head->next, value);

    head->next = result;

    if (result != nullptr)
    {
        result->prev = head;
    }
    return head;


}
DNode* DoublyLinkedList::DeletebyValue(DNode* head, int value) {
if (head == nullptr) {
return nullptr;
}

if (head->data == value)
{
    DNode* nextNode = head->next;

    if (nextNode != nullptr)
    {
        nextNode->prev = nullptr;
    }

    delete head;
    return nextNode;
}
head->next = DeletebyValue(head->next, value);

if (head->next != nullptr)
{
    head->next->prev = head;
}
return head;
}
pair <int, int> DoublyLinkedList:: FindPair(DNode* head, int target) {
   
    return FindPairHelper(head, head, target);
}

pair <int, int> DoublyLinkedList::FindPairHelper(DNode* startNode, DNode* currentNode, int target) {
    if (currentNode == nullptr)
    {
        return {-999, -999};
    }
    int complement = target - currentNode->data;
    DNode* match = searchForValue(currentNode->next, complement);

    if (match!= nullptr)
    {
        return {currentNode->data, match->data};
    }
}
DNode* searchForValue(DNode* node, int targetValue)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->data == targetValue)
    {
        return node;
    }

    return searchForValue(node->next, targetValue);
}
DNode* DoublyLinkedList::Flatten(DNode* head) {
    if (head == nullptr)
    {
        return head;
    }
    FlattenHelper(head);
}

DNode* FlattenHelper(DNode* node) {
    DNode* current = node;
    DNode* last = node;
    DNode* nextNode;
    while (current != nullptr)
    {
        nextNode = current->next;

        if (current->child != nullptr)
        {
            DNode* childTail = FlattenHelper(current->child);

            current->next = current->child;
            current->child->prev = current;
            current->child = nullptr;

            if (nextNode != nullptr)
            {
                childTail->next = nextNode;
                nextNode->prev = childTail;
            }
            last = childTail;

            current = nextNode;
        }
        else {
            last = current;
            current = current->next;
        }

    }
    return last;

}
DNode* RotatebyK(DNode* head, int k) {

    if (k == 0 || head == nullptr || head->next == nullptr)
    {
        return head;
    }
    return rotateHelper(head, k);
}

DNode* rotateHelper(DNode* head, int k) {
    DNode* first = head;
    DNode* newHead = head->next;
    newHead->prev = nullptr;

    DNode* tail = newHead;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = first;
    first->prev = tail;
    first->next = nullptr;

    return rotateHelper(newHead, k - 1);
}
#endif //DOUBLYLINKEDLIST_H
