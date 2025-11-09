#include "DLL.h"
#include <iostream>
using namespace std;


int main() {
    DLL Sora;
    Sora.insertHead(7);
    Sora.insertHead(8);
    Sora.insertTail(6);
    Sora.insertHead(9);
    Sora.insertHead(5);
    Sora.Print();
   //cout << "\nThe middle value in the linked list is " << Sora.Middle()->val << endl;
    if (Sora.HasCycle()) {
        cout << "This linked list does have a cycle.\n";
    }
    else {
        cout << "No, this linked list does not have a cycle.\n";
    }
   // Sora.Print();
   return 0;
}

