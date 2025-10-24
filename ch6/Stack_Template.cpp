//Fixed Capacity Array-Based Stack

#include <stdexcept>
template <typename T, int Capacity>
class ArrayStack{
    private:
        T data[Capacity];
        int topIndex = -1;

    public:
        void push(T value) {
            if(topIndex >= Capacity  - 1)
            {
                throw std::overflow_error("Stack is full");
            }
            else {
                data[++topIndex] = value;  //This increases the value of topIndex by 1, and THEN sets data[topIndex] to value...
        }
        }
    T pop() {
        if(topIndex < 0) {
            throw std::underflow_error("Stack is empty");
        }
        else {
            return data[topIndex--]; //This returns the value of data[topIndex], and THEN decreases it by 1.
        }
    }
};

int main() {
    ArrayStack<int, 10> stack;
}