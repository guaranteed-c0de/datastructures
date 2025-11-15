#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList Sora;
    Sora.insert(3);
    Sora.insert(4);
    Sora.insert(5);

    Sora.print();

   // Node* RecursivelyReverse(Sora.head);
    cout << endl << endl;
    Sora.print();
    return 0;
}