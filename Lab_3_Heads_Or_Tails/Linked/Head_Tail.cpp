#include "unsorted.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
     srand(time(0));
    UnsortedType LinkedListList;
    ItemType x;
    int i = 0;
    bool found;
    int which_iteration = 1 + (rand() %99); //Which iteration in the loop should the program stop to reprint the list.
   
    

    while (i <= MAX_ITEMS)
    {
        if (i = 0) {
            cout << "Here is the list at the beginning.\n";
            LinkedListList.Head();
            LinkedListList.Tail();
            for (i = 0; i < LinkedListList.GetLength(); i++)
            {
                x.Print(cout);
                cout << " ";
            }
            cout << endl << endl;
        }
        else if (i = which_iteration)
        {
            cout << "Here is the list at iteration " << i + 1 << endl;
            LinkedListList.Head();
            LinkedListList.Tail();
            for (i = 0; i < LinkedListList.GetLength(); i++)
            {
                x.Print(cout);
                cout << " ";
            }
            cout << endl << endl;

        }
        else if (i = MAX_ITEMS)
        {
            cout << "Here is the list at the end.\n";
            LinkedListList.Head();
            LinkedListList.Tail();
            for (i = 0; i < LinkedListList.GetLength(); i++)
            {
                x.Print(cout);
                cout << " ";
            }
            cout << endl << endl;

        }
        int random_number = 1 + (rand()% 100);
        x.Initialize(random_number);
        LinkedListList.GetItem(x, found);
        if (!found)
        {
            LinkedListList.PutItem(x);
        }
        i++;
    } 
}