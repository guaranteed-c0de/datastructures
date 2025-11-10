template <typename T>
class CircularLinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node (T val) : data(val), next(nullptr) {}
    }
    Node* topNode;
    int count;
public:
    CircularLinkedLStack() : topNode(nullptr), count(0) {}
    void push(T item) {
        newNode = new Node(val);
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
       T value = topNode->val;
       tempPtr = topNode;
       topNode = topNode->next;
       delete tempPtr;
       return value;
    }
    T top()
    {
        return topNode->val;
    }
};