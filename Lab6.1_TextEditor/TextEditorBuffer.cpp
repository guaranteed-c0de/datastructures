#include "TextEditorBuffer.h"
template <typename T>
void TextEditorBuffer<T>::type(T item) {
buffer.push(item);
}
template <typename T>
void TextEditorBuffer<T>::undo() {
    redoQueue.enqueue(buffer.pop());
}
template <typename T>
void TextEditorBuffer<T>::redo() {
    buffer.push(redoQueue.dequeue());
}

template <typename T>
void TextEditorBuffer<T>::displayBuffer() const {
    while (!buffer.isEmpty())
    {
        cout << buffer.pop() << endl;
    }
}
