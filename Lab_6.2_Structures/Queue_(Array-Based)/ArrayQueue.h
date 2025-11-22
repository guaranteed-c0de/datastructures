#include <iostream>
using namespace std;
#include <string>
template <typename T>
class Queue {
    static const int MAX = 1000;
    T arr[MAX];
    
    int front, rear;

    public:
        Queue() : front(0), rear(-1) {}
        void Enqueue(T value); //Change
        T Dequeue(); //Change
        T GetFront() const; //Change
        bool IsEmpty() const;
        bool IsFull() const;
        void ReverseK(Queue& q, int k) const;
        int SlidingWindowMaximum(int arr[], int n, int k, int out[]);

       // void generateBinary(int n);
};
template <typename T>
class StackfromQueue {
    Queue <T> Q1;
    Queue <T> Q2;
    T pop();
    void push(T item);
    T peek();
};
template <typename T>
class Tree{
    struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};
Queue Q;
void Traversal(TreeNode* root);

};
template <typename T>
T StackfromQueue<T>::pop() {

    if (!Q1.IsEmpty())
        return Q1.Dequeue();
    else if (!Q2.IsEmpty())
        return Q2.Dequeue();
    else {
        throw std::underflow_error("Stack is empty, no elements can be removed.\n");
    }
}
template <typename T>
void StackfromQueue<T>::push(T item) {
    if (Q1.IsEmpty())
    {
        Q1.Enqueue(item);
        while (!Q2.IsEmpty())
    {
       int temp = Q2.Dequeue();
       Q1.Enqueue(temp);
    }
    }
    
    else {
        Q2.Enqueue(item);
        while (!Q1.IsEmpty())
        {
            int temp = Q1.Dequeue();
            Q2.Enqueue(item);
        }
    }
}
template <typename T>
T StackfromQueue<T>::peek() {
    if (!Q1.IsEmpty()) {
        return Q1.GetFront();
    }

    else if (!Q2.IsEmpty()) {
        return Q2.GetFront();
    }
    else if (Q2.IsEmpty() && Q1.IsEmpty()) {
         throw std::underflow_error("Stack is empty, no elements can be seen.\n");
    }
    }

