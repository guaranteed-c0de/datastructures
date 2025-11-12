#include <iostream>
using namespace std;
#include <stdexcept>
template <typename T>

class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;
public:
    Stack() : capacity(100), topIndex(-1) {arr = new T[capacity];}
    void push(T item) {
        if (isFull())
        {
            throw std::overflow_error("Stack is full, no items can be added.\n");
        }
        else {
            topIndex++;
            arr[topIndex] = item;
        }
    }
    T pop() {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty, no items can be removed.\n");
            return;
        }
        else {
            return arr[topIndex--];
        }
    }
    T top() const{
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty, no item is at the top.\n");
            return;
        }
        else {
        return arr[topIndex];
        }
    }
    bool isEmpty() const{
        return topIndex < 0;
    }
    bool isFull() const {
        return topIndex >= capacity - 1;
    }
    int size() const {
        return topIndex + 1;
    }
    ~Stack() {
        delete[] arr;
    }
};