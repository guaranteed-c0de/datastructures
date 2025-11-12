#include "Array_Queue.h"
#include "Array_Stack.h"
#include "Circular_Linked-List_Queue.h"
#include "Circular_Linked-List_Stack.h"
#include "Circular_Linked-List.h"
template <typename T>

class TextEditorBuffer {
    CircularLinkedStack<T> buffer;
    CircularLinkedQueue<T> redoQueue;

public:
    void type(T item) {
        buffer.push(item);
    }
    void undo() {
        redoQueue.enqueue(buffer.pop());
    }
    void redo() {
        buffer.push(redoQueue.dequeue());
    }
    void displayBuffer() const {
         while (!buffer.isEmpty())
    {
        cout << buffer.pop() << endl;
    }
    }
};
