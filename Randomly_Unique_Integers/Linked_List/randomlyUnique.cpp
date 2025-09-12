#include "unsorted.h"
#include <fstream>
UnsortedType list_x;
#include <iostream>
using namespace std;
#include <bits/stdc++.h>    
   int main()
   { 
    bool found;
    ofstream outputFile("list_x_file.txt");
    srand(time(0));
    if (outputFile.is_open()) {
        // File opened successfully, proceed to write
    } else {
        // Handle error: file could not be opened
        // For example, print an error message to the console
        std::cerr << "Error opening file!" << std::endl;
    }
   ItemType itemx;
    for (int i = 1; i <= MAX_ITEMS; i++)
    { if(i%10 == 1)
        {
            cout << endl;
            outputFile << endl;
        }
        
         int randomNumber = rand() % 100;
        itemx.Initialize(randomNumber); //Gives the node the number of the value of i.
        list_x.PutItem(itemx); //Puts the item in the list.
        itemx.Print(cout); //Prints the number out TO THE CONSOLE.
       itemx.Print(outputFile); //Prints the number out TO THE OUTPUT FILE ("list_x_file.txt")
        
        cout << " ";
        outputFile << " ";
    }
   cout << "The length of the list is " << list_x.GetLength() << endl;
   /*  outputFile << "Hello, world!" << std::endl; */
}