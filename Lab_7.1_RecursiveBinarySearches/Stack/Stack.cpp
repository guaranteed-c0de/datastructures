#include "Stack.h"
#include <iostream>

int main() {
    Stack Ventus;
    Ventus.push(5);
    Ventus.push(10);
    Ventus.push(3);
    Ventus.push(4);
    Ventus.push(2);
    Ventus.push(15);

    Ventus.Print();
    Ventus.sortStack();
    Ventus.Print();
}