#include "unsorted.h"
#include <fstream>
UnsortedType list_x;
#include <iostream>
using namespace std;
#include <bits/stdc++.h>    
   int main()
   { 
    int i = 1;
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
    while (i <= MAX_ITEMS)  //This will be the index. It will be useful for counting through to make sure each value in the list is accounted for.
    { 
        
         int randomNumber = rand() % 100; //Modular arithmetic. The number can be between 0 and 99.
        itemx.Initialize(randomNumber); //Gives the node the number the randomly generated number.
        list_x.GetItem(itemx, found);
        if (!found) //if the randomly generated number was not found, i.e. this number doesn't already exist in the array. This means the number can be added to the array.
        {
            if(i%10 == 1) //If the index is 1, 11, 21, etc. a new line will form for the numbers.
        {
            cout << endl;
            outputFile << endl;
        }
        list_x.PutItem(itemx); //Puts the item in the list.
        itemx.Print(cout); //Prints the number out TO THE CONSOLE.
       itemx.Print(outputFile); //Prints the number out TO THE OUTPUT FILE ("list_x_file.txt")
        
        cout << " "; //Adds a space TO THE CONSOLE.
        outputFile << " "; //Adds a space TO THE OUTPUT FILE ("list_y_file.txt")
        i++; //Important that this is in the if statement. Otherwise, the i would increment regardless of whether or not a number was added to the array. We want this index to be in the same pace as the numbers being added to the array.
        } //End of if statement.
         
    }
   //End of while loop.
} //End of randomlyUnique.cpp