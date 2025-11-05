#include <iostream>
#include <string>
using namespace std;
class PrintJob{
    public:
        string* pages; //array of page strings
        int pageCount; //number of pages
        int numCopies;
        PrintJob(string pgs[], int n, int copies) {
            pageCount = n;
            numCopies = copies;
            pages = new string[n];
            for (int i = 0; i < n; i++)
            {
                pages[i] = pgs[i];
            }
        }
};

struct Node {
    PrintJob* job;
    Node* next;
    Node(PrintJob* j): job(j), next(NULL) {}
};

class Printer {
    Node* head;
    int currPage;
    int currCopy;

    public:
        Printer();
        void sendJob(PrintJob* job);
        bool hasNext();
        string next(); //throws runtime_error if empty.
};