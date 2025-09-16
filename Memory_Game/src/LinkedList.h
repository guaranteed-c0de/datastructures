#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept> //So we can throw the exception.
class LinkedList {
    private:
        Node* head;
        int length;
    public:
        LinkedList() : head(nullptr), length(0) {}

        ~LinkedList() {
            Node* current = head;
            while (current) {
                Node* temp = current;
                current = current ->next;
                delete temp;
            }
        }
    void insert(Card card) {
        Node* newNode = new Node(card);
        if(!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp -> next) temp = temp->next;
            temp->next = newNode;
        }
        length++;
    }
    Card& getAt(int index){
        if(index < 0 || index >= length) throw std::out_of_range("Invalid Index");
        Node* temp = head;
        for(int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void removeAt(int index) {
        if(index < 0 || index >= length) return;
        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* prev = head;
            for(int i = 0; i< index - 1; i++)
            {
                prev = prev -> next;
            }
            Node* temp = prev -> next;
            prev -> next = temp-> next;
        }
        length--;
    }
    int size() const {return length;}
};
#endif //LINKEDLIST_H