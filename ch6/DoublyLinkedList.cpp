

template <typename T>
class DoublyLinkedList {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;
            Node(T val) : data(val), next(nullptr), prev(nullptr) {}
        };

        Node* head = nullptr;
        Node* tail = nullptr;
        int size = 0;
    
        public:
            ~DoublyLinkedList() {
                while(!IsEmpty()) removeAtFront();
            }
            void InsertAtFront(T value) {
                Node* newNode = new(value);

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
};