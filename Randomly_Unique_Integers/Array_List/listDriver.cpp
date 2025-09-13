// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "unsorted.h"

using namespace std; 
void PrintList(ofstream& outFile, UnsortedType& list); //The ampersand means that one would still pass the objects of the data types, but it'll hold onto the addresses as the value is passed to the function.

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
 
  int number;
  ItemType item;
  UnsortedType list;
  bool found;
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());
 
  cout << "Enter name of test run; press return." << endl;
  cin >> outputLabel;

  outFile << outputLabel << endl;
  if(!inFile)
  {
    cout << "File not found." << endl;
	exit(2);
  }

  inFile >> command;

  numCommands = 0;
  while (command != "Quit")
  { 
    cout << command;
    if (command == "PutItem")
    {
      inFile >> number; 
      item.Initialize(number);
      list.PutItem(item);
      item.Print(outFile);
      outFile << " is in list." << endl;
    }
    else if (command == "DeleteItem")
    {
      inFile >> number;
      item.Initialize(number);
      list.DeleteItem(item);
      item.Print(outFile);
      outFile << " is deleted." << endl;
    }
    else if (command == "GetItem")
    {
      inFile >> number;
      item.Initialize(number);
      item = list.GetItem(item, found);
      if (found)
        outFile << number << " found in list." << endl;
      else outFile << number  << " not in list."  << endl;  
    } 
    else if (command == "GetLength")  
      outFile << "Length is " << list.GetLength() << endl;
    else if (command == "IsFull")
      if (list.IsFull())
        outFile << "List is full." << endl;
      else outFile << "List is not full."  << endl;  
    else if (command == "MakeEmpty")
	  list.MakeEmpty();
	else if (command == "PrintList")
	  PrintList(outFile, list);
	else cout << " Command not recognized." << endl;
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;   
  };
 
  cout << "Quit" << endl << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}; //End of function main. Why is there a semi-colon?


void PrintList(ofstream& dataFile, UnsortedType& list) //Not to be confused with the function Print() from ItemType.cpp and ItemType.h.
// Pre:  list has been initialized.      
//       dataFile is open for writing.   
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.         
{
  int length;
  ItemType item;
  dataFile << "PrintList" << endl;
  list.ResetList();
  length = list.GetLength();
  if (length == 0)
    dataFile << "List is empty.";
  else
    for (int counter = 1; counter <= length; counter++)
    {
      item = list.GetNextItem();
      item.Print(dataFile);
    }
  dataFile << endl; 
} //End of listDriver.cpp
