#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <utility>
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
        bool FindCycle(Node* head2);
        bool DetectCycle (Node* head1, Node* head2);
        Node* MergeSortedLists(Node* headn1, Node* headn2);
        Node* RemoveDuplicate(Node* headplh);
        Node* DetectDuplicate(Node* headplh);
        bool DuplicateExists(Node* nodeplh, int value);
        std::pair<Node*, Node*> partitionList(Node* head, int x);
        std::pair<Node*, Node*> partitionHelper(Node* node, int x);
        
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


bool LinkedList::FindCycle(Node* head)
{
    return DetectCycle(head->next, head->next->next);
}

bool LinkedList::DetectCycle(Node* slow, Node* fast)
{
    if (fast == slow || fast == nullptr || fast->next == nullptr)
    {
        if (!fast || !fast->next)
        {
            return false;
        }
        else {
            return true;
        }
    }
    DetectCycle(slow->next, fast->next->next);
}

Node* LinkedList::MergeSortedLists(Node* headn1, Node* headn2)
{
    Node* mergedHead;
    if (!headn1 && !headn2) {

    }
    if (!headn1)
    {
        return headn2;
    }
    else if(!headn2) {
        return headn1;
    }

    if (headn1->data <= headn2->data)
    {
       mergedHead = headn1;
        mergedHead->next = MergeSortedLists(headn1->next, headn2);
    }

    else {
        mergedHead = headn2;
        mergedHead->next = MergeSortedLists(headn1, headn2->next);
    }
    return mergedHead;
}

Node* LinkedList::RemoveDuplicate(Node* headplh)
{
    return DetectDuplicate(headplh);
}

Node* LinkedList::DetectDuplicate(Node* nodeplh) {
    if (!nodeplh)
    {
        return nullptr;
    }
    nodeplh->next = DetectDuplicate(nodeplh->next);

    if (DuplicateExists(nodeplh->next, nodeplh->data))
    {
        return nodeplh->next;
    }

    else {
        return nodeplh;
    }
}

bool LinkedList::DuplicateExists(Node* node, int value) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value)
    {
        return true;
    }
    return DuplicateExists(node->next, value);
}
std::pair <Node*, Node*> LinkedList::partitionList(Node* head, int x) {
    auto [lesserHead, greaterHead] = partitionHelper(head, x);
    return {lesserHead, greaterHead};

    cout << "This is the first partition:\n";

    print(lesserHead);

    cout << endl << endl;
    print(greaterHead);
}

std::pair <Node*, Node*> LinkedList::partitionHelper(Node* node,int x) {
if (node == nullptr)
{
    return {nullptr, nullptr};
}
auto [lowerList, higherList] = partitionHelper(node->next, x);

if (node->data < x)
{
    node->next = lowerList;
    return {node, higherList};
}
else {
    node->next = higherList;
    return {lowerList, node};
}
}
#endif //LINKED_LIST_H