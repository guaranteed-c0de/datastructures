#include <iostream>
using namespace std;
#include <string>
class Queue {
    static const int MAX = 1000;
    int arr[MAX];
    
    int front, rear;

    public:
        Queue() : front(0), rear(-1) {}
        void Enqueue(int x); //Change
        int Dequeue(); //Change
        int GetFront() const; //Change
        bool IsEmpty() const;
        bool IsFull() const;
        void ReverseK(Queue& q, int k) const;

       // void generateBinary(int n);
};

class StackfromQueue {
    Queue Q1;
    Queue Q2;
    int pop();
    void push(int item);
    int peek();
};
class Tree{
    struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};
void Traversal(TreeNode* root);

};
