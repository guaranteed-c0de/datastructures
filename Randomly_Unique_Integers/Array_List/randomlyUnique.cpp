#include "unsorted.h"
#include <fstream>
#include <bits/stdc++.h>  //Includes a variety of libraries, including <cstlib>, which allows us to use srand().
#include <iostream>
using namespace std;
UnsortedType list_y; //Hardly a justified reason for this declaration to included with the libraries and the namespace, but it's so this object is out of the way.


int main()
{
    int i = 1; //This will be the index. It will be useful for counting through to make
    bool found;
    ofstream outputFile("list_y_file.txt");
    srand(time(0));
    if (outputFile.is_open()) {
        // File opened successfully, proceed to write
    } else {
        // Handle error: file could not be opened
        // For example, print an error message to the console
        std::cerr << "Error opening file!" << std::endl;
    }
   ItemType itemy;
   while (i <= MAX_ITEMS)
    { 
        
         int randomNumber = rand() % 100; //Modular arithmetic. The number can be between 0 and 99.
        itemy.Initialize(randomNumber); //Gives the node the number the randomly generated number.
        list_y.GetItem(itemy, found);
        if (!found) //if the randomly generated number was not found, i.e. this number doesn't already exist in the array. This means the number can be added to the array.
        {
            if(i%10 == 1) //If the index is 1, 11, 21, etc. a new line will form for the numbers.
        {
            cout << endl;
            outputFile << endl;
        }
        list_y.PutItem(itemy); //Puts the item in the array.
        itemy.Print(cout); //Prints the number out TO THE CONSOLE.
       itemy.Print(outputFile); //Prints the number out TO THE OUTPUT FILE ("list_y_file.txt")
        
        cout << " "; //Adds a space TO THE CONSOLE.
        outputFile << " "; //Adds a space TO THE OUTPUT FILE ("list_y_file.txt")
        i++; //Important that this is in the if statement. Otherwise, the i would increment regardless of whether or not a number was added to the array. We want this index to be in the same pace as the numbers being added to the array.
        } //End of if statement.
         
    } //End of while loop.
} //End of randomlyUnique.cpp