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

       // void generateBinary(int n);
};
template <typename T>
class StackfromQueue {
    Queue Q1;
    Queue Q2;
    int pop();
    void push(int item);
    int peek();
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
