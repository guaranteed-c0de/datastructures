// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"

ItemType::ItemType() //Default constructor for the ItemType's value.
{ 
  value = 0; //But I'd probably define constructors in the header files. They are special cases, anyway.
}

RelationType ItemType::ComparedTo(ItemType otherItem) const //Definition of ComparedTo function.
{
  if (value < otherItem.value) 
    return LESS; 
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL; 
}

void ItemType::Initialize(int number) //Here, the value within the array index can be changed to the value that was called in.
{ //This appears to be no different than a setter function.
  value = number;
}

void ItemType::Print(std::ostream& out) const //This const means it WILL NOT change any of the class's member variables.
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value; //This prints out to the output file, not the console.
}
//End of ItemType.cpp.
