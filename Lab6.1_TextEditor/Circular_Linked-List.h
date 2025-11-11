#include <iostream>
template <typename T>
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
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
        }
        else {
            Node* loc = head->next;
            Node* prev = nullptr;
            while (loc != head)
            {
                prev = loc;
                loc->prev;
            }
            prev->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        count++;
    }
    void insertRear(T item)
    {
        Node* newNode = new Node(item);
         if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
        }
        else {
            Node* loc = tail->next;
            Node* prev = nullptr;
            while (loc != tail)
            {
                prev = loc;
                loc= loc->next;
            }
            prev->next = newNode;
            newNode->next = head;
            tail = newNode;

        }
        count++;
    }
    void deleteFront() {
        if (isEmpty()) {
            throw std::underflow_error("List is empty, no item can be removed.");
        }
        else {
            temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            count--;
        }
    }
    void deleteRear() {
        if (isEmpty()) {
            throw std::underflow_error("List is empty, no item can be removed.");
        }
        else {
            temp = rear;
            Node* loc = head;
            Node* prev = nullptr;
            while (loc != rear)
            {
                prev = loc;
                loc = loc->next;
            }
            prev->next = head;
            tail = prev;
            delete temp;
            count--;
        }

    }
    void display() const{
        Node* loc = head;
        for (int i = 1; i<= count)
        {
            cout << loc->data << endl;
            loc = loc->next;
        }
    }
    bool isEmpty() const {return count == 0;}
    int size() const {return count;}
    ~CircularLinkedList() {
        Node* loc = head;
        for (int i = 1; i<= loc; i++)
        {
            Node* temp = loc;
            loc = loc->next;
            delete temp;
        }
    }
};