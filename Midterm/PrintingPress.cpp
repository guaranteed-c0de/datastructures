#include "PrintingPress.h"
#include <stdexcept>

Printer::Printer() {
    head = nullptr;
    currPage = 0;
    currCopy = 0;
}
bool Printer::hasNext() {
return next == nullptr;
}
string Printer::next() {
   if (head == nullptr) {
    cout << "Empty.\n";
   }
   PrintJob* job = head->job;
}

void Printer:: sendJob(PrintJob* job) {
    Node* loc = head;
    Node* newNode = new Node(job);
    while (loc->next != nullptr)
    {
        loc = loc->next;
    }
    loc->next = newNode;
}

