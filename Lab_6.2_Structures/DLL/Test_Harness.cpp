#include "DLL.h"
#include <iostream>
using namespace std;


int main() {
    DLL Sora;
    Sora.insertHead(7);
    Sora.insertHead(8);
    Sora.insertTail(6);
    Sora.insertHead(9);
    Sora.insertHead(89);
    Sora.insertHead(5);
    Sora.Print();
    Sora.DeleteNode(Sora.tail->prev->prev);
    Sora.Print();
   // Sora.Print();
}

