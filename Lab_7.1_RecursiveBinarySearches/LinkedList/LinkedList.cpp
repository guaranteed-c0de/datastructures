#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList Sora;
    Sora.insert(3);
    Sora.insert(4);
    Sora.insert(5);

    Sora.print(Sora.head);

    Sora.head = Sora.RecursivelyReverse(Sora.head);
    cout << endl << endl;
    Sora.print(Sora.head);
    return 0;
}