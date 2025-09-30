#include "unsorted.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
     srand(time(0));
    UnsortedType LinkedListList;
    ItemType x;
    int which_iteration = 1 + (rand() %99); //Which iteration in the loop should the program stop to reprint the list.
    int random_number = 1 + (rand()% 100);
    cout << which_iteration << endl;
    cout << random_number;
    /*for (int i = 0; i <= MAX_ITEMS; i++)
    {
        if (i = 0) {
            LinkedListList.Head();
            LinkedListList.Tail();
            
        }

    } */
}