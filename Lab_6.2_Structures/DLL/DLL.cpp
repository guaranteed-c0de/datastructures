#include "DLL.h"
#include <iostream>
#include <stdexcept>
using namespace std;
void DLL::insertHead(DLLNode*& head, int val) //Allocate node, set prev = nullptr, link to old head, update head
{
DLLNode* newNode = new DLLNode(val);
head = newNode;
head->prev = nullptr;
head->next = nullptr;
tail = newNode;
}
void DLL::insertTail(DLLNode*& tail, int val)
{
    DLLNode* temp = tail; 
    DLLNode* newNode = new DLLNode(val);
    tail = newNode;
    tail-> prev = temp;
    temp->next = newNode; 
    if (IsEmpty())
    {
        head = tail;
    }  
 }
bool DLL:: IsEmpty()
{
    return head == nullptr;
}
void DLL::DeleteHead(DLLNode* & head, DLLNode* & tail) {
    if (IsEmpty()) {
        throw std::underflow_error("List is empty, head cannot be removed.\n");
    }
    else {
DLLNode* temp = head;
head = head->next;
head->prev = nullptr;
delete temp;
    }
}
void DLL::DeleteTail(DLLNode* & head, DLLNode* & tail) {
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
}

void DLL::InsertAfter(DLLNode* node, int val) {
    DLLNode* newNode = new DLLNode(val);
    newNode->next = node->next;
    node->next = newNode;
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
       node = node->next;
       delete temp;
    }
}

void::Reverse(DLLNode*& head, DLLNode*& tail) { //head points to the node that the tail does...
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
    loc->prev = last;

   }




}

int main() {
    DLL list;
    list.head = nullptr;
    list.tail = nullptr;
    list.insertHead(list.head, 20);
    list.insertHead(list.head, 10);
    DLLNode* p = list.head;

    while (p)
    {
        cout << p->val << endl;
        p = p->next;
    }
    
    return 0;
}

