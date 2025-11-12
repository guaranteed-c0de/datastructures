#include <iostream>
using namespace std;
#include <stdexcept>
template <typename T>

class CircularLinkedQueue {
    private:
        struct Node {
            T data;
            Node* next;
            Node (T val) : data(val), next(nullptr) {}

        };
        Node* rear;
        int count;

    public:
        CircularLinkedQueue() : rear(nullptr), count(0) {}
        void enqueue(T item) {
            Node* newNode = new Node(item);
            if (isEmpty())
            {
                rear = newNode;
                newNode->next = rear;
            }
            else {
                newNode->next = rear->next; 
                rear->next = newNode;       
                rear = newNode;    
                
            }
            count++;
        }
        T dequeue() {
            if (isEmpty())
            {
                throw std:: underflow_error("The list is empty. No item can be removed.");
            }
            else if (count == 1)
            {
                T value = rear->data;
                Node* temp = rear;
                rear = nullptr;
                delete temp;
                count--;
                return value;
            }
            else {
           T value = rear->data;
            Node* temp = rear;
            Node* loc = rear->next;
            Node* prev = nullptr;
            while (loc != rear)
            {
                prev = loc;
                loc = loc->next;
            }
            prev->next = rear->next;
            rear = rear->next;
            delete temp;
            count--;
            return value;
            }
        }
        T front() const {
            if (isEmpty()) {
                throw std::underflow_error("The list is empty. There is no item at the front.");
            } 
            return rear->data;
        }
        bool isEmpty() const {
            return count == 0;
        }
        int size() const {
            return count;
        }
        ~CircularLinkedQueue() {
            if (!rear) return;
            Node* front = rear->next;
            rear->next = nullptr;
            Node* loc = front;

            while(loc)
            {
                Node* temp = loc;
                loc = loc->next;
                delete temp;
            }
            rear = nullptr;
            count = 0;
        }
};