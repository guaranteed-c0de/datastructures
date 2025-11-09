#include "DLL.h"
#include <iostream>
using namespace std;


int main() {
    DLL Sora;
    Sora.insertHead(6);
    Sora.insertTail(90);
    Sora.DeleteTail();
    Sora.Print();
}

