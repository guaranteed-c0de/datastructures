//
#include <std_except>
template <typename T>

class ArrayHeap {
    private:
    T* array;
    int capacity;
    int size;
    Compare comp;
    int parent(int i) const {return (i-1)/2;}
    int left(int i) const {return 2*i + 1;}
    int right(int i) const {return 2*i + 2;}

    void resize() {
        int newCapacity = capacity*2;
        T* newArray = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
    void heapifyUp(int i) {
        while (i >0 && comp(array[i], array[parent(i)])) {
            std::swap(array[i], array[parent(i)]);
            i = parent(i);
        }
    }
    void heapifyDown(int i) {
        while (true) {
            int best = i;
            int l = left(i);
            int r = right(i);

            if (l < size && comp(array[l], array[best]))
                best = l;
            if (r < size && comp(array[r], array[best]))
                best = r;

            if (best = i)
                break;
           // std::swap()
        }
    }

    public:
    explicit ArrayHeap(int capacity=100)
        :capacity(capacity), size(0), array(new T[capacity]) {}
        ~ArrayHeap() {delete[] array;} //We delete because it's dynamic, and will be allocated to the heap.
        ArrayHeap(const ArrayHeap& other)
        :capacity(other.capacity), size(other.size), array(new T[other.capacity]) {

            for (int i = 0; i < size; ++i)
            {
                array[i] = other.array[i];
            }
        }

        ArrayHeap& operator=(const ArrayHeap& other) {
            if (this == &other) return *this;
            capacity = other.capacity;
            size = other.size;
            for (int i = 0; i< size; ++i)
            {
                array[i] = other.array[i];
            }
            return *this;
        }

        bool IsEmpty() const {return size==0;}
        int getSize() const {return size;}
        void push(T value) {
            if (size == capacity)
                resize();

            array[size] = value;
            heapifyUp(size);
            size++;
        }
        T peek() const {
            if (IsEmpty()) throw std::underflow_error("Heap is empty.");
            return array[0];
        }
        T pop {
            if (IsEmpty()) {
                std::underflow_error("Heap is empty.");
                T value = array[0];
                array[0] = array[size - 1];
                size--;
                if (size > 0)
                    heapifyDown(0);
                    return value;
            }
        }
};

void buildFromArray(const T* arr, int n)

class MaxCompare{
    public:
        bool operator(int a, int b) const {return a > b};
};

template <typename T>
class MaxHeap: public ArrayHeap<T, MaxCompare> {
    public:
        MaxHeap(int capacity=100) : ArrayHeap <T, MaxCompare>(capacity) {}
};


class MinCompare {
    bool operator() (int a, int b) const {return a < b;}
};
template <typename T>
class MinHeap : public ArrayHeap<int, MinCompare> {
    public:
        MinHeap(int capacity = 100) : ArrayHeap<int, MinCompare>(capacity) {}
};