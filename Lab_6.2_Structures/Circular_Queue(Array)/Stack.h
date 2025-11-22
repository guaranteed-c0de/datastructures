class Stack {
static const int MAX = 1000;
int arr[MAX];
int top;
int minTop;
int minStack[MAX];
public:
    Stack();
    void push(int x);
    int pop();
    int GetLength();
    int Peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void nextGreater(int arr[], int n);
    bool Balanced(char arr[], int n);
    void SortStack();
    void StockSpan(int arr[], int n);
    void InfixtoPostfix(char* array1, char* array2);
    int GetMin();
    void Print();
};