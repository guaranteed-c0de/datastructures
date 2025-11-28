#ifndef HEAPMASTER_CPP
#define HEAPMASTER_CPP
#include "HeapMaster.h"
#include <stdexcept>
using namespace std;
template <typename T, int MAX_SIZE, typename Compare>
const T& HeapMaster<T, MAX_SIZE, Compare>::top() const {
    if (Isempty())
    {
        throw std::underflow_error("List is empty,");
    }
    return data[0];
}

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::push(const T& val) {
     if (current_size >= MAX_SIZE)
        throw std::overflow_error("Heap is full.\n");
    data[current_size] = val;
    heapifyUp(current_size);
    current_size++;
}

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::pop() {
     if (Isempty())
        throw std::underflow_error("Heap is empty.\n");
    data[0] = data[current_size - 1];
    current_size--;
    heapifyDown(0);
}

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyUp(int i) {
    while (i > 0 && comparator(data[i], data[parent(i)])) {
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyDown(int i) {
    while (true) {
        int l = left(i);
        int r = right(i);
        int best = i;

        if (l < current_size && comparator(data[l], data[best]))
            best = l;

        if (r < current_size && comparator(data[r], data[best]))
            best = r;

        if (best == i) break; // heap property satisfied

        std::swap(data[i], data[best]);
        i = best;
    }
}

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::printArray() const{
cout << "This is the (raw array) heap.\n";
    for (int i = 0; i <= current_size - 1; i++)
{
    cout << data[i] << endl;
}
cout << "End of array.\n";
}





#endif //HEAPMASTER_H