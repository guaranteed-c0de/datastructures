#include <iostream>
using namespace std;
template <typename T>

class LinkedList {

    private:

    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    int size;

    public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    ~LinkedList() {
       Node* current = head;
        while(current!= nullptr) {
            Node* nextNode = current->next;
        }
    }

    void Insert(T item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        size++;
    }
    void printList() {
        printListHelper(head);
    }
    void printListHelper(Node* current) {

        if (current == nullptr) return;
        while (current)
        {
        std::cout << current->data << " ";
        current = current->next;
        }
        
        
    }
};

int main() {
    LinkedList<int> alex;
    alex.Insert(5);
    alex.Insert(15);
    alex.Insert(25);

    alex.printList();
} //Depth determines complexity.

// O(b^n)

//Factorial function has both time complexity and space complexity of O(n).