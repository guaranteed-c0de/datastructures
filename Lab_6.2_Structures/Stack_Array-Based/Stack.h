class Stack {
static const int MAX = 1000;
int arr[MAX];
int top;

public:
    Stack();
    void push(int x);
    int pop();
    int Peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void Print();
};