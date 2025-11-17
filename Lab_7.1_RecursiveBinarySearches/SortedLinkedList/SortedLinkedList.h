#include <iostream>
using namespace std;
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next{nullptr} {}
};

class SortedLinkedList {
    public:
        Node* head;
        SortedLinkedList() : head(nullptr) {}
        void insert(int val);
        void print(Node* head);
        bool BinarySearch(Node* head, int target);
        Node* QuickSort(Node* head);
        Node* MergeSort(Node* head);
};

void SortedLinkedList:: insert(int val) {
Node* newNode = new Node(val);

if (head == nullptr)
{
    head = newNode;
}

else if (val <= head->data)
{
    newNode->next = head;
    head = newNode;
}

else {
   Node* loc = head;

   while (loc != nullptr && loc->data < val)
   {
    loc = loc->next;
   }

   if (loc == nullptr)
   {
    loc = newNode;
   }
   else {
    newNode->next = loc;
    loc = newNode;
   }
}
}


void SortedLinkedList:: print(Node* head) {
Node* loc = head;
cout << "This is the list.\n";

while (loc != nullptr)
{
    cout << loc->data << endl;
    loc = loc->next;
}
}
bool SortedLinkedList::BinarySearch(Node* head, int target) {
    if (!head) return false;

    int size = countNodes(head);
    if (size == 0) return false;

    int midIndex = size/2;
    Node* mid = getNodeAt(head, midIndex);
    if (mid->data == target) return true;
    if (target < mid->data) {
        Node* leftEnd = getNodeAt(head, midIndex - 1);
        Node* savedNext = (leftEnd ? leftEnd->next : nullptr);
        if (leftEnd) leftEnd ->next = nullptr;
        bool found = BinarySearch(head, target);
        if (leftEnd) leftEnd->next = savedNext;
        return found;
    }
    else {
        return BinarySearch(mid->next, target);
    }
}
int countNodes(Node* head) {
    if (!head) return 0;
    return 1 + countNodes(head->next);
}
Node* getNodeAt(Node* head, int index) {
    if (index == 0) return head;
    return getNodeAt(head->next, index - 1);
}
Node* getTail(Node* head) {
    while (head && head->next) head = head->next;
    return head;
}

void partition(Node* head, Node* pivot, Node** less, Node** greater) {
    if (!head) return;
    partition(head->next, pivot, less, greater);
    if (head->data < pivot->data) {
        head->next = *less;
        *less = head;
    }
    else {
        head->next = *greater;
        *greater = head;
    }
}

Node* SortedLinkedList::QuickSort(Node* head) {
    if (!head || !head->next)
    {
        return head;
    }

    Node* pivot = getTail(head);
    Node* less = nullptr;
    Node* greater = nullptr;

    Node* temp = head;
    while (temp->next != pivot) {
        temp = temp->next;
    }
    temp->next = nullptr;

    partition(head, pivot, &less, &greater);

    Node* sortedLess = QuickSort(less);
    Node* sortedGreater = QuickSort(greater);


    Node* newHead = sortedLess ? sortedLess : pivot;

    if (sortedLess) {
        getTail(sortedLess)->next = pivot;
    }
    pivot->next = sortedGreater;

    return newHead;
}

Node* SortedLinkedList::MergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

   Node* mid = findMiddle(head);
   Node* rightHalf = mid->next;
   mid->next = nullptr;

  Node* leftSorted = MergeSort(head);
  Node* rightSorted = MergeSort(rightHalf);

  return merge(leftSorted, rightSorted);
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* list1, Node* list2) {

    if (!list1)
    {
        return list2;
    } 

    if (!list2)
    {return list1;}
    if (list1->data <= list2->data)
    {
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else {
        list2->next = merge(list1, list2->next);
        return list2;
    }
} //O(n) time complexity.


#endif //SORTEDLINKEDLIST_H