#include "TextEditorBuffer.h"


int main() {
TextEditorBuffer<char> editor;
editor.type('S');
editor.type('u');
editor.type('b');
editor.type('s');
editor.type('c');
editor.type('i');
editor.type('b');
editor.type('e');
editor.type('!');
editor.displayBuffer();
    return 0;
}