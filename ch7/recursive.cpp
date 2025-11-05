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
        current = head;
        while(current!= nullptr) {
            Node* nextNode = current->next;
        }
    }

    void Insert(T item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = head;
    }
    void printList() {
        printListHelper(head);
    }
    void printListHelper(Node* current) {

        if (current == nulltpr) return;
        std::cout << current->data << " ";
        printListHelper(current->next);
    }
};