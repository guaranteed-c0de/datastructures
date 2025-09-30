#include "unsorted.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
     srand(time(0));
    UnsortedType ArrayList;
    ItemType y;
    int i = 0;
    bool found;
    int which_iteration = 1 + (rand() %49); //Which iteration in the loop should the program stop to reprint the list.
    cout << "I will randomly show the list at iteration " << which_iteration << endl;
    

    while (i < MAX_ITEMS)
    {
        if (i == 0 || i == which_iteration || i == MAX_ITEMS - 1) {
            if (i == 0)
            {
            cout << "Here is the list at the beginning.\n"; }
            if (i == which_iteration)
            {
                 cout << "Here is the list at iteration " << i  << endl;
            }
            if (i == MAX_ITEMS - 1)
            {
                cout << "Here is the list at the end." << endl;
            }
           try {
            cout << "Head: ";
            ArrayList.Head().Print(cout);
            cout << endl;
                    } catch (const std::runtime_error& e) {
                cout << "Head: " << e.what() << endl;
                                }
            try {
            cout << "Tail: ";
            ArrayList.Tail().Print(cout);
                cout << endl;
                    } catch (const std::runtime_error& e) {
                cout << "Tail: " << e.what() << endl;
                    }
            ArrayList.ResetList(); 
            for (int l = 0; l < ArrayList.GetLength(); l++)
            {
                ItemType temp = ArrayList.GetNextItem();
             temp.Print(cout);
             cout << " ";
            }
            cout << endl << endl;
        }
        int random_number = 1 + (rand()% 100);
        y.Initialize(random_number);
        ArrayList.GetItem(y, found);
        if (!found)
        {
            ArrayList.PutItem(y);
            i++;
        }
        
    } 
}