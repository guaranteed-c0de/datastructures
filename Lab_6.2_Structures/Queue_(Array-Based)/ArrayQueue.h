class Queue {
    static const int MAX = 1000;
    int arr[MAX];
    int front, rear;

    public:
        Queue() : front(0), rear(-1) {}
        void Enqueue(int x);
        int Dequeue();
        int GetFront() const;
        bool IsEmpty() const;
        bool IsFull() const;
        void ReverseK(Queue& q, int k) const;
};