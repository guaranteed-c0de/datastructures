
#include <stdexcept>
class FixedFrontQueue{
    private:
        int* array;
        int capacity;
        int rear; //front int isn't always necessary. It's always 0.
        int front = 0;

    public:
        FixedFrontQueue(int size): capacity(size), rear(-1) {
            array = new int[size];
        }
        ~FixedFrontQueue() 
        {
            delete[] array;
        }
        void Enqueue(int item) {
            if(rear == capacity) {
                throw std::overflow_error("Queue is full");
            }
            rear++;
        }
        int Dequeue() {
            if(rear == 0) {
                throw std::underflow_error("Queue is empty");
            }
            int item = array[0];
            for(int i = 0; i < rear - 1; i++) {
                array[i] = array[i + 1];
            }
            --rear;
            return item;
        }
        bool IsEmpty() const{
            return rear == front;
        }

        bool IsFull() const {
            return rear == capacity;
        }
        int size() const{
            return rear;
        }
};