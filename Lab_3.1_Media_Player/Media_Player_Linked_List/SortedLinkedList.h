#include <iostream>
#include <string>
#include "ItemType.h"
#include "List.h"
#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H
using namespace std;



struct SNode {
    ItemType* item;
    SNode* next;
    SNode(ItemType* i) : item(i), next(nullptr) {}
    ~SNode() {delete item;}
};

class SortedLinkedList: public List {

    protected:
        SNode* listData;
        int length;
        SNode* currentPos;

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
        SNode* newSNode = new SNode(item); //Pointer to SNode being added.
        SNode* predLoc; //Trailing pointer.
        SNode* location; //Traveling pointer.
        location = listData; 
        predLoc = nullptr;
        bool moreToSearch = (location != NULL);

        //Find insertion point.
       if(!moreToSearch || item -> LessThan(*(location->item)))
       {
        newSNode-> next = listData;
        listData = newSNode;
       }
       else{

        while(location -> next != nullptr && !(item->LessThan(*(location->next->item))))
        {
            location = location ->next;
        }
        newSNode -> next = location -> next;
        location -> next = newSNode;
       }
        length++;
    }

    virtual void Remove(ItemType& item) override {
        SNode* current = listData;
        SNode* prev = nullptr;
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

        SNode* current = listData;
        while (current != nullptr) {
            if (current -> item -> CompareTo(item)) {
                    return true;
            }
            current = current -> next;
        }
        return false;
    }
     virtual void ListItems() const override{

        SNode* current = listData;
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
    virtual int GetLength() const override{
            return length;
    }
    

    virtual void Clear() override {
        SNode* tempPtr;
        while (listData != nullptr) {
            tempPtr = listData;
            listData = listData -> next;
            delete tempPtr;
        }
        length = 0;
        length = length;
        currentPos = nullptr;
    }
    virtual void Merge(SortedLinkedList& other) override {
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

   
};
#endif //SORTED_LINKED_LIST_H