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
    void type(T item) {/*Push to buffer, log to history.*/}
    void undo() {/*Pop from buffer, enqueue to redoQueue*/}
    void redo() {/*Dequeue from redoQueue, push to buffer*/}
    void displayBuffer() const {/*Display buffer contents.*/}
};
