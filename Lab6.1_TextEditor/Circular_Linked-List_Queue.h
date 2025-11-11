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
                Node* loc = rear;
                Node* prev = nullptr;
                while (loc)
                {
                    prev = loc;
                    loc = loc->next;
                }
                prev->next = newNode;
                newNode->next = rear;
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
                value = rear->data;
                Node* temp = rear;
                rear = nullptr;
                delete temp;
                count--;
                return value;
            }
            else {
            value = rear->data;
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
            Node* loc = rear;

            for (int i = 1; i <= count; i++)
            {
                Node* temp = loc;
                loc = loc->next;
                delete temp;
            }
            cout = 0;
        }
};