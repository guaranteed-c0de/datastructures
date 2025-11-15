#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList Sora;
    Sora.insert(3);
    Sora.insert(4);
    Sora.insert(5);

    LinkedList Sora2;
    Sora2.insert(1);
    Sora2.insert(4);
    Sora2.insert(16);

    LinkedList Sora3;
    Sora3.head = Sora3.MergeSortedLists(Sora.head, Sora2.head);

    Sora3.print(Sora3.head);
    return 0;
}