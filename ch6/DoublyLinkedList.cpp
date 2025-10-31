
#include <stdexcept>
template <typename T>
class DoublyLinkedList {
    private:
        struct Node { //size = 0, head, tail = ptr.
            T data;
            Node* next;
            Node* prev;
            Node(T val) : data(val), next(nullptr), prev(nullptr) {} //Remember, when a Node is initialized, its next and prev pointers are initialized to nullptr.
        };
        //
        Node* head = nullptr;
        Node* tail = nullptr;
        int size = 0;
    
        public:
            ~DoublyLinkedList() {
                while(!IsEmpty()) removeAtFront();
            }
            void InsertAtFront(T value) {
                Node* newNode = new(value); //Initializes up here.

                if (!head) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                    newNode->next = head;
                    head-> prev = newNode;
                    head = newNode;
                  
                }
                size++;
            }
            void InsertAtFront(T value) {
                Node* newNode = new(value);

                if (!head) {
                    head = newNode;
                    tail = newNode;
                }
                else {
                     tail->next = newNode;
                     newNode->prev = tail;
                     tail = newNode;
                   
                }
                size++;
            }
            void removeAtFront() {
                temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
            T RemoveAtFront() {
               
              
                if (!head) throw std::underflow_error("List is empty"); //Base class exception. Exceptions are always a RUNTIME error.
                 T value = head->data;
                Node* temp = head;
                head = head->next;
                if (head) head->prev = nullptr;
                else {tail = nullptr;}
                delete temp;
                size--;
                return value;
            }
            void removeAtEnd() {
                temp = tail;
                tail = 
            }

};

int main() {
    DoublyLinkedList<int> list;
    list.InsertAtFront(20);
    list.InsertAtFront(30);
}