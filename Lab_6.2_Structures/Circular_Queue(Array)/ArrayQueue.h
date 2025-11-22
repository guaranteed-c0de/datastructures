class CircularQueue {
private:
    static const int MAX = 1000;
    int arr[MAX];
    int front, rear, size;
public:
    CircularQueue(): front(0), rear(-1), size(0){} 
    void Enqueue (int x);
    int Dequeue();
    int GetFront() const;
    bool IsEmpty() const;
    bool IsFull() const;  
    void firstNegative(int arr[], int n, int k);
    int CircularTour(int petrol[], int dist[], int n);
    void Rotate(CircularQueue& q, int k);
    bool IsPalindrome(const char* s);
    void PrintReverse(CircularQueue& q);
    bool Remove(int x);
    int CircularTour( int petrol[], int dist[], int n);
    void PrintQueue();
};