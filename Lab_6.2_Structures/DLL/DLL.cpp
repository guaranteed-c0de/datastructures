#include "DLL.h"
#include <iostream>
using namespace std;
void DLL::insertHead(DLLNode*& head, int val) //Allocate node, set prev = nullptr, link to old head, update head
{
DLLNode* newNode = new DLLNode(val);
head = newNode;
head->prev = nullptr;
head->next = nullptr;
tail = newNode;
} //comment
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

