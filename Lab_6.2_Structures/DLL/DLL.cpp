#include "DLL.h"
#include <iostream>
#include <stdexcept>
using namespace std;

DLL::DLL() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}
void DLL::insertHead(int val) //Allocate node, set prev = nullptr, link to old head, update head
{
DLLNode* newNode = new DLLNode(val);
if (IsEmpty()) {
head = newNode;
head->prev = nullptr;
head->next = nullptr;
tail = newNode;
}
else {
    newNode->next = head;
    head = newNode;
}
length++;
}
void DLL::insertTail(int val)
{
   
    DLLNode* newNode = new DLLNode(val);
    
    /*tail = newNode;
    tail-> prev = temp;
    temp->next = newNode; */
    if (IsEmpty())
    {
        tail = newNode;
        head = tail;
    }  
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
 }
bool DLL:: IsEmpty()
{
    return head == nullptr;
}
void DLL::DeleteHead() {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty, head cannot be removed.\n");
    }
    else {
DLLNode* temp = head;
head = head->next;
head->prev = nullptr;
delete temp;
    }
    length--;
}
void DLL::DeleteTail() {
    if (IsEmpty())
    {
          throw std::underflow_error("List is empty, tail cannot be removed.\n");
    }
    else {
        DLLNode* temp = tail;
tail = tail->prev;
tail->next = nullptr;
delete temp;
    }
    length--;
}

void DLL::InsertAfter(DLLNode* node, int val) {
    DLLNode* newNode = new DLLNode(val);
    newNode->next = node->next;
    newNode->prev = node;
    node->next = newNode;
    newNode->next->prev = newNode;
    length++;
}
void DLL::DeleteNode(DLLNode* node) {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty, node cannot be removed.\n");
    }
    else if(node == head || node == tail) {
        throw std::out_of_range("Cannot be deleted from this function call.\n");
    }
    else {
    
       DLLNode* temp = node;
       node->prev->next = node->next;
      node ->next->prev = node->prev;
       
       delete temp;
    }
    length--;
}

void DLL::Reverse() { //head points to the node that the tail does...
   DLLNode* temp = head;
   head = tail;
   tail = temp;
   head->next = head->prev;
   head->prev = nullptr;
   DLLNode* loc = head->next;
   DLLNode* last = head;


   while (loc != tail)
   {
    DLLNode* temp_ptr = loc;
    loc->next = loc->prev;
    loc->prev = last;
    last = loc;
    loc = loc->next;
   }

   loc->prev = last;
   loc->next = nullptr;




}
DLLNode* DLL:: Middle() {
    bool odd = (length%2 == 1);
   int middle = length/2;
if (odd)
{
    middle++;
}
DLLNode* loc = head;

for (int i = 1; i < middle; i++)
{
    loc = loc->next;
}
return loc;
}

bool DLL::HasCycle() {
    DLLNode* tortoise = head;
    DLLNode* hare = head;
    tortoise = tortoise->next;
    hare = hare->next->next;

    while (hare != nullptr && hare->next != nullptr && hare != tortoise)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    if (hare == tortoise)
    {
        return true;
    }
    else {
        return false;
    }
}

void DLL::Print() {
    cout << "Here is what the linked list looks like now:\n";
    DLLNode* loc = head;
    while (loc!=nullptr)
    {
        cout << loc->val << endl;
        loc = loc->next;
    }
    cout << endl;
}

