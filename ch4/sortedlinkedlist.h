#ifndef EXAMPLES_SORTEDLINKEDLIST_H
#define EXAMPLES_SORTEDLINKEDLIST_H

#include "unsortedlinkedlist.h"

class SortedLinkedList : public unsortedlinkedlist(){

    public:
    SortedLinkedList(): UnsortedLinkedList() {}

void Insert(ItemType* item) override {

    Node* newNode = new Node(item);
    Node* current = listData;
    Node* prev = nullptr;

    while (current!= nullptr && currrent->item->LessThan(*item)) {
        prev = current;
        current = current-> next;
    }
    if (prev == nullptr) {
        newNode -> next = listData;
        listData = newNode;
    }
    else {
        newNode->next = current;
        prev -> next = newNode; //Does an ADT provide implementation?
    }
}
void Remove(ItemType &item) ovveride {
    //For number 4. Run a for loop with a switch statement. Why not an if/else statement?
}
};
#endif //EXAMPLES_SORTEDLINKEDLIST_H