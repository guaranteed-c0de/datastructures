#include <iostream>
template <template T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* rear;
    int count;
public:
    CircularLinkedList() : head(nullptr), rear(nullptr), count(0) {}
    void insertFront(T item) {
        Node* newNode = new Node(item);
        if (isEmpty())
        {
            
        }
    }
};