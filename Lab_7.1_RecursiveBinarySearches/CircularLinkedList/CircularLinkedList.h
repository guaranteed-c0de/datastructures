#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include <iostream>
#include <utility>
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
        void DeleteNode(CNode* node, CNode* original);
        std::pair<CNode*, CNode*> SplitCircularList(CNode* head);
        std::pair<CNode*, CNode*> SplitHelper(CNode* head, CNode* slow, CNode* fast);
        int Josephus(CNode* head, int k);
        int JosephusHelper(CNode* node, int k);
       
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
void CircularLinkedList:: DeleteNode(CNode* startNode, CNode* original) {
  if (startNode->next == startNode)
  {
    delete startNode;
    return;
  }

  if (startNode == original)
  {
    startNode->data = startNode->next->data;
    CNode* temp = startNode->next;
    startNode->next = startNode->next->next;
    delete temp;
    return;
  }

  DeleteNode(startNode->next, original);
}

std::pair<CNode*, CNode*> CircularLinkedList::SplitCircularList(CNode* head) {
    if (head == nullptr || head->next == head)
    {
        return {head, nullptr};
    }

    return SplitHelper(head, head, head);
}

std::pair<CNode*, CNode*> CircularLinkedList::SplitHelper(CNode* head, CNode* slow, CNode* fast) {
    if (fast->next == head || fast->next->next == head)
    {
        CNode* head1 = head;
       CNode* head2 = slow->next;

       slow->next = head1;

       if (fast->next == head)
        {
            fast->next = head2;
        }
        else {
            fast->next->next = head2;
        }
        return {head1, head2};
    }
    return SplitHelper(head, slow->next, fast->next->next);
}

int CircularLinkedList::Josephus(CNode* head, int k)
{
    return JosephusHelper(head, k);
}

int CircularLinkedList::JosephusHelper(CNode* node, int k) {
    if (node->next == node) {
        return node->data;
    }

    for (int i = 1; i < k; i++)
    {
        node = node->next;
    }
    CNode* Removed = node->next;

    node->next = Removed->next;

    delete Removed;

    return JosephusHelper(node->next, k);

}

#endif //CIRCULAR_LINKED_LIST_H