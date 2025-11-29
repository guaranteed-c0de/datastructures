#include "DLL.h"
#include <iostream>
using namespace std;


int main() {
    DLL Sora;
    Sora.insertTail(10);
    Sora.insertTail(7);
    Sora.insertTail(13);
    Sora.insertTail(23);
    Sora.Print();
    Sora.DeleteNode(Sora.head->next);
   //cout << "\nThe middle value in the linked list is " << Sora.Middle()->val << endl;
    //if (Sora.HasCycle()) {
      //  cout << "This linked list does have a cycle.\n";
    //}
    //else {
      //  cout << "No, this linked list does not have a cycle.\n";
   // }
   // Sora.Print();
   Sora.Print();
   return 0;
}

