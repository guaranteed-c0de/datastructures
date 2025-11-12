#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class CircularLinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node (T val) : data(val), next(nullptr) {}
    };
    Node* topNode;
    int count;
public:
    CircularLinkedStack() : topNode(nullptr), count(0) {}
    void push(T item) {
       Node* newNode = new Node(item);
        if (isEmpty()) {
            topNode = newNode;
        }
        else {
            newNode->next = topNode;
            topNode = newNode;
        }
        count++;
    }
    T pop() {
       T value = topNode->data;
      Node* tempPtr = topNode;
       topNode = topNode->next;
       delete tempPtr;
       count--;
       return value;
    }
    T top() const
    {
        if (isEmpty())
        {
            throw std:: underflow_error("The stack is empty, no item at the top.");
        }
        return topNode->data;
    }
    bool isEmpty() const {
        return count == 0;
    }
    int size() const {
        return count;
    }
    ~CircularLinkedStack() {
        while (topNode)
        {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        count = 0;
    }
};