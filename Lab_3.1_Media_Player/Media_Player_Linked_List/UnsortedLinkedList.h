#include <iostream>
#include <string>
#include "ItemType.h"
#include "List.h"
#include "Song.h"
#ifndef UNSORTED_LINKED_LIST_H
#define UNSORTED_LINKED_LIST_H
using namespace std;
#include "Song.h"
#include "SortedLinkedList.h"



class UnsortedLinkedList: public List {

    protected:
        Node* listData;
        int length;
        Node* currentPos;

    public:
        UnsortedLinkedList() {
            listData = nullptr;
            length = 0;
            currentPos = nullptr;

        }
    ~UnsortedLinkedList() {
        Clear();
    }
   
    virtual void Insert(ItemType* item) override {
        Node* location = new Node(item);
        location -> next = listData;
        listData = location;
        length++;
    }

    virtual void Remove(ItemType& item) override {
        Node* current = listData;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current -> item -> CompareTo(item)) { //So current might not point to an item? Well, perhaps just not any one specific one.
                if (prev == nullptr) {
                    listData = current -> next; //Current points to the item that will be deleted.
                }
                else {
                    prev -> next = current -> next; //Why doesn't the value of prev change here?
                }
                delete current;
                length --;
                return;
            }
            prev = current;
            current = current -> next;
        }
    }

    virtual bool IsPresent(const ItemType& item) const override {

        Node* current = listData;
        while (current != nullptr) {
            if (current -> item -> CompareTo(item)) {
                    return true;
            }
            current = current -> next;
        }
        return false;
    }
     virtual void ListItems() const override{

        Node* current = listData;
        if (current == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }
        while (current != nullptr)
        {
            current -> item -> Print(cout);
            std:: cout << endl;
            current = current -> next;
        }
    }
     virtual bool IsEmpty() const override{
        return length == 0;
    }
    virtual int GetNumberOfItems() const override{
            return length;
    }
    virtual void Clear() override {
        Node* tempPtr;
        while (listData != nullptr) {
            tempPtr = listData;
            listData = listData -> next;
            delete tempPtr;
        }
        length = 0;
        currentPos = nullptr;
    }
     void SortThis(SortedLinkedList& sorted) {
         Node* current = this->listData;
    while (current != nullptr) {
        sorted.Insert(current->item);  // Insert keeps it sorted
        current = current->next;
    }
    }

   
};
#endif //UNSORTED_LINKED_LIST_H