#include <iostream>
#include <stdexcept>
template <typename T>
class Queue {
    private:
    T* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

    public:
        Queue() : capacity(100), frontIndex(0), rearIndex(-1), count(0) {arr = new T[capacity]; }
        void enqueue (T item) {
            if (isFull())
            {
                throw std:: overflow_error("The queue is full, no item can be added.");
            }
            else {
                rearIndex = rearIndex + 1% capacity;
                arr[rearIndex] = item;
                count++;
            }
        }
        T dequeue() {
            if (isEmpty())
            {
                throw std:: underflow_error("The list is empty, no items can be removed.");
            }
            else {
                return arr[frontIndex];
                frontIndex = frontIndex + 1%capacity;
                count--;
            }
        }
        T front() const {
            if (isEmpty())
            {
                throw std::underflow_error("The queue is empty, there are no items at the top.");
            }
            else {
            return arr[frontIndex];
            }
        }
        bool isEmpty () const {
            return count == 0;
        }
        bool isFull() const {
            return count == capacity;
        }
        int size() {
            return count;
        }
        ~Queue() {
            delete[] arr;
        }
};