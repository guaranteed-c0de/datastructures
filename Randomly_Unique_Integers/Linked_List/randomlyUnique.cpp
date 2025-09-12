#include "unsorted.h"
#include <fstream>
UnsortedType list_x;
#include <iostream>
using namespace std;
    
   int main()
   { 
    bool found;
    ofstream list_x_file;
    std::ofstream outputFile("list_x_file"); 
    if (outputFile.is_open()) {
        // File opened successfully, proceed to write
    } else {
        // Handle error: file could not be opened
        // For example, print an error message to the console
        std::cerr << "Error opening file!" << std::endl;
    }
   ItemType itemx;
    for (int i = 1; i <= MAX_ITEMS; i++)
    {
        itemx.Initialize(i);
        list_x.PutItem(itemx);
       
        
        cout << endl;
    }
   cout << "The length of the list is " << list_x.GetLength() << endl;
   /*  outputFile << "Hello, world!" << std::endl; */
}