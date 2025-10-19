#include <iostream>
#include <string>
#include "ItemType.h"
#include "List.h"
#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H
using namespace std;




class SortedLinkedList: public List {

    protected:
        Node* listData;
        int length;
        Node* currentPos;

    public:
        SortedLinkedList() {
            listData = nullptr;
            length = 0;
            currentPos = nullptr;

        }
    ~SortedLinkedList() {
        Clear();
    }
   
    virtual void Insert(ItemType* item) override {
        Node* newNode = new Node(item); //Pointer to Node being added.
        Node* predLoc; //Trailing pointer.
        Node* location; //Traveling pointer.
        location = listData; 
        predLoc = nullptr;
        bool moreToSearch = (location != NULL);

        //Find insertion point.
       if(!moreToSearch || item -> LessThan(*(location->item)))
       {
        newNode-> next = listData;
        listData = newNode;
       }
       else{

        while(location -> next != nullptr && !(item->LessThan(*(location->next->item))))
        {
            location = location ->next;
        }
        newNode -> next = location -> next;
        location -> next = newNode;
       }
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
        length = length;
        currentPos = nullptr;
    }
     void Merge(SortedLinkedList& other)  {
            Node temp(nullptr); // temporary head for result
            Node* tail = &temp; // keeps track of end of merged list
            Node* playlistptr1 = this->listData;
            Node* playlistptr2 = other.listData;

            while (playlistptr1 != nullptr && playlistptr2 != nullptr)
            {
                if(playlistptr1->item->LessThan(*playlistptr2->item))
                {
                    tail->next = playlistptr1;
                    playlistptr1 = playlistptr1 ->next;
                }
                else {
                    tail-> next = playlistptr2;
                    playlistptr2 = playlistptr2->next;
                }
                tail = tail->next;
            }
            //Add extra nodes.
            tail->next = (playlistptr1 != nullptr) ? playlistptr1: playlistptr2;
            

            this->listData = temp.next;
            this->length += other.length;

            //Empty the 'other' playlist

            other.listData = nullptr;
            other.length = 0;
    }
   virtual Node* GetHead() override {
        return listData;
    }
    virtual int GetNumberOfItems() const override {
        return length;
    }
   
};
#endif //SORTED_LINKED_LIST_H