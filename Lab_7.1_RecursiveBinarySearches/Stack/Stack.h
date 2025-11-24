#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
#include <stdexcept>
#include <string>
#include <cctype>
template <typename T>
struct Node{
T val;
Node* next;
Node(T val) : data(val), next(nullptr) {}
};
template <typename T>
class Stack{
public:
    Node* top;
    int length;
    Stack() : top(nullptr), length(0) {}
    void push(T val);
    T pop();
    T peek();
    bool isEmpty();
    void Print();
    void sortStack();
    void SortHelper(int value);
    void Reverse();
    void insertAtBottom(int value);
    int EvaluatePostfix();
    int EvaluateHelper();
};
template <typename T>
void Stack<T>::push(T val) {
    Node* newNode = new Node(val);
    if (isEmpty())
    {
        top = newNode;
    }
    else {
        newNode->next = top;
        top = newNode;
    }
    length++;
}
template <typename T>
T Stack<T>::pop() {
    if (isEmpty())
    throw std::underflow_error("List is empty.");
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    length--;
    return x;
}
template <typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}
template <typename T>
T Stack<T>::peek() {

    if (isEmpty())
     throw std::underflow_error("List is empty.");
    return top->data;
}
template <typename T>
void Stack<T>::Print() {
    if (isEmpty())
    {
        throw std::underflow_error("List is empty.");
    }
    cout << "Here is the stack:\n";
    Node* loc = top;
    while (loc)
    {
        cout << loc->data << endl;
        loc = loc->next;
    }
}
template <typename T>
void Stack<T>::sortStack() {
    if (isEmpty())
    {
        return;
    }
    int temp = pop();

    sortStack();
    SortHelper(temp);
}
template <typename T>
void Stack<T>::SortHelper(int value) {
    if (isEmpty() || top->data <= value)
    {
        push(value);
        return;
    }
    

    int temp = pop();
    SortHelper(value);

    push(temp);
}
template <typename T>
void Stack<T>::Reverse() {
    if (isEmpty())
    {
        return;
    }
    int temp = pop();
    Reverse();

    insertAtBottom(temp);
}
template <typename T>
void Stack<T>::insertAtBottom(int value) {
    if (isEmpty()) {
        push(value);
        return;
    }
    int temp = pop();
    insertAtBottom(temp);

}

template <typename T>
int Stack<T>::EvaluatePostfix() {
return EvaluateHelper(); 
}
template <typename T>
int Stack<T>::EvaluateHelper() {
char token = pop();
if (isdigit(static_cast<unsigned char>)(token));
{
    return (token - '0');
}


int rightValue = EvaluateHelper();
int leftValue = EvaluateHelper();

return Operate(leftValue, rightValue, token);
}

int Operate(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
}
#endif //STACK_H 