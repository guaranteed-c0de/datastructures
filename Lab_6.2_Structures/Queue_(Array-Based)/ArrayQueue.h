#include <iostream>
using namespace std;
#include <string>
class Queue {
    static const int MAX = 1000;
    string arr[MAX];
    
    int front, rear;

    public:
        Queue() : front(0), rear(-1) {}
        void Enqueue(string x); //Change
        string Dequeue(); //Change
        string GetFront() const; //Change
        bool IsEmpty() const;
        bool IsFull() const;
        void ReverseK(Queue& q, int k) const;
        void generateBinary(int n);
};