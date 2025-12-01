#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class Queue {
public:
    Node* front;
    Node* rear;
    int length;
    Queue() : front(nullptr), rear(nullptr), length(0) {}
    void enqueue(T val);
    T dequeue();
    bool isEmpty();
    void reverseQueue(); //O(n)
    int GetLength(); //O(n)
    Node<T>* interleaveQueue(Queue<T>& Q); //O(n)
    void OneToN(int n); //O(n)
    

};
template <typename T>
int Queue<T>::GetLength() {
    Node* loc = rear;
    while (loc)
    {
        loc = loc->next;
        length++;
    }
    return length;
}
template <typename T>

void Queue<T>::enqueue(T val) {
     Node* newNode = new Node(val);
    if (!front && !rear){
        front = newNode;
        rear = newNode;
    }
   else {
    rear->next = newNode;
    rear = newNode;
   }
   length++;
}

template <typename T>
T Queue<T>::dequeue() {

    if (isEmpty())
    {
        throw std:: underflow_error("The list is empty.\n");
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    delete temp;
    return value;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return front == nullptr;
}
template <typename T>
void Queue<T>::reverseQueue() { 
    if (front == nullptr || front == rear)
    {
        return;
    }
    int temp = dequeue();
    reverseQueue();

    enqueue(temp);
} //O(n) time complexity... //Comment.

template <typename T>
Node<T>* Queue<T>::interleaveQueue(Queue<T>& Q) {
    if (Q.isEmpty())
    {
        return nullptr;
    }
    int Nnodes = Q.GetLength();
    if (Nnodes%2 != 0)
    {
        cout << "Invalid queue. There must be an even number of elements.";
        return nullptr;
    }
    Queue<T> temp;

    for (int i = 1; i <= Nnodes/2; i++)
    {
        temp.enqueue(Q.dequeue());
    }
    interleaveHelper(temp, Q);
    return Q.rear;
}
template <typename T>
void interleaveHelper(Queue<T> FirstHalf, Queue<T> SecondHalf)
{
    if (FirstHalf.isEmpty())
    {
        return;
    }
   int a = FirstHalf.dequeue();
   int b = SecondHalf.dequeue();

   interleaveHelper(FirstHalf, SecondHalf);

   SecondHalf.enqueue(a);
   SecondHalf.enqueue(b);
}
template <typename T>
void Queue<T>::OneToN(int n) {
Queue Q;
Q.enqueue("1");

RecursiveHelper(Q, n);
}
template <typename T>
void RecursiveHelper(Queue<T>& Q, int n)
{
    if (n == 0)
    return;
    string s = Q.dequeue();
    cout << s << endl;
    Q.enqueue(s"0");
    Q.enqueue(s"1");
    RecursiveHelper(Q, n - 1);

}

#endif //QUEUE_H