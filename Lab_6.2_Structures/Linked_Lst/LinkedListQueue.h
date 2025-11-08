#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

struct QNode {
    int val;
    QNode* next;
    QNode(int v) : val(v), next(nullptr) {}
};

class LinkedListQueue {
    public:
        LinkedListQueue() : front(nullptr), rear(nullptr), length(0) {}
        void Enqueue(int x);
        int Dequeue();
        int GetFront();
        bool IsEmpty() const;
        ~LinkedListQueue();
        void Reverse(LinkedListQueue& queue);
        void Print(LinkedListQueue& queue) const;
        LinkedListQueue Merge(LinkedListQueue a, LinkedListQueue b);

    private:
        QNode* front; 
        QNode* rear;
        int length;


};
#endif //LINKEDLISTQUEUE_H