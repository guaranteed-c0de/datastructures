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
    cout << which_iteration << endl;
    

    while (i <= MAX_ITEMS)
    {
        if (i == 0 || i == which_iteration || i == MAX_ITEMS) {
            if (i == 0)
            {
            cout << "Here is the list at the beginning.\n"; }
            if (i == which_iteration)
            {
                 cout << "Here is the list at iteration " << i + 1 << endl;
            }
            if (i == MAX_ITEMS)
            {
                cout << "Here is the list at the end." << endl;
            }
           try {
            cout << "Head: ";
            LinkedListList.Head().Print(cout);
            cout << endl;
                    } catch (const std::runtime_error& e) {
                cout << "Head: " << e.what() << endl;
                                }
            try {
            cout << "Tail: ";
            LinkedListList.Tail().Print(cout);
                cout << endl;
                    } catch (const std::runtime_error& e) {
                cout << "Tail: " << e.what() << endl;
                    }
            LinkedListList.ResetList(); 
            for (int l = 0; l < LinkedListList.GetLength(); l++)
            {
                ItemType temp = LinkedListList.GetNextItem();
             temp.Print(cout);
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