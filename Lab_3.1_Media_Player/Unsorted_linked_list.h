#include <iostream>
#include <string>
#include "ItemType.h"
#ifndef UNSORTED_LINKED_LIST_H
#define UNSORTED_LINKED_LIST_H
using namespace std;



struct Node {
    ItemType* item;
    Node* next;
    Node(ItemType* i) : item(i), next(nullptr) {}
    ~Node() {delete item;}
};

class UnsortedList {

    protected:
        Node* listData;
        int length;
        Node* currentPos;

    public:
        UnsortedList() {
            listData = nullptr;
            length = 0;
            currentPos = nullptr;

        }
    ~UnsortedList() {
        Clear();
    }
    virtual void Clear() {
        Node* tempPtr;
        while (listData != nullptr) {
            tempPtr = listData;
            listData = listData -> next;
            delete tempPtr;
        }
        length = 0;
        currentPos = nullptr;
    }
    virtual void Insert(ItemType* item) {
        Node* location = new Node(item);
        location -> next = listData;
        listData = location;
        length++;
    }

    virtual void Remove(ItemType& item) {
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

    virtual bool IsPresent(const ItemType& item) const {

        Node* current = listData;
        while (current != nullptr) {
            if (current -> item -> CompareTo(item)) {
                    return true;
            }
            current = current -> next;
        }
        return false;
    }
    virtual int getLength() const {
            return length;
    }

    virtual bool IsEmpty() const {
        return length == 0;
    }

    virtual void ListItems() const {

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
};
#endif //UNSORTED_LINKED_LIST_H