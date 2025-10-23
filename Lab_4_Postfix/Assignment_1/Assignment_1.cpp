#include "Stack.h"
#include <iostream>
using namespace std;
int main() {
    Stack simple;
    simple.push(6);
    simple.push(60);
    simple.push(10);
    simple.push(82);
    simple.push(38);
    while (!simple.isEmpty())
{
    cout << simple.peek() << endl;
    cout << simple.pop() << endl;
    cout << simple.isEmpty() << endl;
}
cout << simple.peek() << endl;
cout << simple.pop() << endl;
return 0;
}
