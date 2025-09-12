#include "unsorted.h"
#include <fstream>
UnsortedType list_x;
#include <iostream>
using namespace std;
    
   int main()
   { 
    std::ofstream outputFile("list_x_file"); 
    if (outputFile.is_open()) {
        // File opened successfully, proceed to write
    } else {
        // Handle error: file could not be opened
        // For example, print an error message to the console
        std::cerr << "Error opening file!" << std::endl;
    }
   ItemType item1, item2, item3, item4;
   item1.Initialize(2);
   item2.Initialize(5);
   item3.Initialize(6);
   item4.Initialize(8);

   list_x.PutItem(item1);
   list_x.PutItem(item2);
   list_x.PutItem(item3);
   list_x.PutItem(item4);
   cout << "The length of the list is " << list_x.GetLength() << endl;
   /*  outputFile << "Hello, world!" << std::endl; */
}