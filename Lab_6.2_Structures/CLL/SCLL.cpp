#include "SCLL.h"
#include <stdexcept>
#include <iostream>
using namespace std;
 SCLL::SCLL() {
    head = nullptr;
    tail = nullptr;
    length = 0;
 }
void SCLL::InsertHead(int val) {
SCLLNode* newNode = new SCLLNode(val);
if (head == nullptr) 
{
head = newNode;
tail = newNode;
}
else {
    newNode->next = head->next;
    head = newNode;
    tail->next = newNode;
}
length++;
}

void SCLL::InsertTail(int val) {
   SCLLNode* newNode = new SCLLNode(val);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else {
        SCLLNode* loc = head;
        while (loc != tail)
        {
            loc = loc->next;
        }
        newNode->next = head;
        loc = newNode;
        tail = newNode;

    }

}
void SCLL::DeleteHead() {
    if (length == 0)
    {
        throw std::underflow_error("List is empty, no nodes can be removed.\n");
    }
    else {
    SCLLNode*& temp = head;
    head = head->next;
    delete temp;
    }
}

void SCLL::DeleteLastNode() {
   if(length == 0)
    {
        throw std::underflow_error("List is empty, no nodes can be removed.\n");
    }
    else {
        SCLLNode* loc = head;
        while (loc != tail)
        {
            loc = loc->next;
        }
        SCLLNode* temp = loc;
        loc = head;
        delete temp;
    }
}
int SCLL::Josephus(int k) {
    if (length == 0) {
        throw std::underflow_error("Cannot be performed, the list is empty.");
    }
    else if (length == 1)
    {
        return head->val;
    }
    else if (length > 1)
    {
        SCLLNode* loc = head;
        while (length > 1)
        {
            for (int i = 1; i <=k; i++)
            {
                loc = loc->next;
            }
            SCLLNode* temp = loc;
            loc = loc->next;
            head = loc;
            tail = loc;
            delete temp;
            length--;
        }
        return loc->val;
    }
}

 pair< SCLL::SCLLNode*, SCLL::SCLLNode* > SCLL::Split() {
    int middle = length/2;
    SCLLNode* head1 = head;
    tail->next = head1;
   //Wait. Even doing that will delete the pointer it's connected to. And we don't want that. delete head; 
    SCLLNode* loc = head1;
    
    for (int i = 1; i<=middle; i++)
    {
        loc = loc->next;
    }
   SCLLNode* head2 = loc->next;
   SCLLNode* tail1 = loc;
  // delete loc; I need to make sure each node points to the correct one before deleting them.
   tail1->next = head1;
    SCLLNode* tail2 = tail;
    
 }

 int SCLL::CycleLength() {
    return length;
 }

 void SCLL::SortedInsert(int val) {
    SCLLNode* loc = head;
    if (loc == nullptr)
    {
        InsertHead(val);
    }
    else {
        while (val > loc->val && loc != tail)
        {
            loc = loc->next;
        }
       SCLLNode* newNode = new SCLLNode(val);
       newNode->next = loc->next;
       loc = newNode;
    }
 }
 void SCLL::Print() {
    cout << "This is currently the list.\n";
    SCLLNode* loc = head;
    for (int i = 1; i<=length; i++) {
        cout << loc->val << endl;
        loc = loc->next;
    }
 }
