#ifndef HEAPMASTER_CPP
#define HEAPMASTER_CPP
#include "HeapMaster.h"
#include <stdexcept>
using namespace std;
template <typename T, int MAX_SIZE, typename Compare>
const T& HeapMaster<T, MAX_SIZE, Compare>::top() const {
    if (Isempty())
    {
        throw std::underflow_error("List is empty.\n");
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

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::printHeap() const {
    cout << "This is the array, in heap form.\n";

    if (current_size == 0) {
        std::cout << "Heap is empty.\n";
        return;
    }

    int depth = GetDepth();
    int maxWidth = pow(2, depth); // number of nodes on last level
    int index = 0;

    for (int level = 0; level <= depth; ++level) {
        int nodesOnLevel = pow(2, level);     // 2^level
        int spacesBetween = maxWidth / nodesOnLevel;

        // Print leading spaces
        std::cout << std::string(spacesBetween * 2, ' ');

        // Print all nodes on this level
        for (int i = 0; i < nodesOnLevel && index < current_size; ++i) {
            std::cout << data[index++];

            // Spacing between siblings
            std::cout << std::string(spacesBetween * 4, ' ');
        }

        std::cout << "\n\n"; // extra line for visual separation
    }
}

template <typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::sortHeap() {
    for (int i = current_size/2 - 1; i >= 0; --i)
    {
        heapifyDown(i);
    }
    int originalsize = Getsize();

    for (int i = current_size - 1; i > 0; --i)
    {
        swap(data[0], data[i]);
        current_size--;
        heapifyDown(0);
    }
    current_size = originalsize;
}

template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::decreaseKey(int index, const T& newVal) {
    if (index < 0 || index >= current_size)
        return false;
        //For min-heap: New value must be SMALER (higher priority)
        //For max-heap: we interpret "decreaseKey" as making it worse -> use increaseKey instead
    if constexpr (std::is_same_v<Compare, std::less<T>>) {
        if (comp(newVal, data[index])) { //newVal < old -> not allowed in min-heap decreaseKey
            return false;
        }
    } else {//In max-heap, decreaseKey means making it smaller (worse priority)
            //We'll allow it, but most scheduling uses min-heap on remaining time.
            if (comp(data[index], newVal)) {//Old > new -> making it worse
                //This is actually increaseKey in max-heap terms->use increaseKey logic.
                data[index] = newVal;
                heapifyDown(index);
                return true;
            }
    }

    //Standard decreaseKey (improving priority)
    data[index] = newVal;
    heapifyUp(index);
    return true; //Bubble up because it got better.
}

//increaseKey: Make element at index 'idx' worse (lower priority)
//Used in max-heap when priority drops, or in SRTF when remaining time increases.
template <typename T, int MAX_SIZE, typename Compare>
bool HeapMaster <T, MAX_SIZE, Compare>::increaseKey(int idx, const T& newVal) {
        if (idx < 0 || idx >= current_size)
        return false;

        if constexpr (std::is_same_v<Compare, std::less<T>>) {
            //min-heap: increaseKey = make value larger (worse priority)
            if (comp(newVal, data[idx])) return false; //newVal < old ->not increase
        }
        else {
            //max-heap: increaseKey = make value smaller (worse)
            if (comp(data[idx], newVal)) return false; //old > new->not increase
        }

        data[idx] = newVal;
        heapifyDown(idx);           //sink down because it got worse
        return true;
} //SRTF means Shortest Remaining Time First.
#endif //HEAPMASTER_H