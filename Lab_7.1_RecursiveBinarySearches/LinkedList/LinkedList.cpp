#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList Sora;
    Sora.insert(3);
    Sora.insert(4);
    Sora.insert(5);

    cout << "The middle is " << Sora.findMiddle(Sora.head)->data;
    return 0;
}