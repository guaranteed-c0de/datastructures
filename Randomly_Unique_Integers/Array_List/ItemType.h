// The following declarations and definitions go into file 
// ItemType.h. 

#include <fstream> //fstream is a class in the <fstream> library that handles operations regarding having the console read to and from files.
const int MAX_ITEMS = 50; //Ironically, this value had to be changed for randomlyUnique.cpp.
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
  ItemType();
  RelationType ComparedTo(ItemType) const; //ComparedTo can return EQUAL, GREATER, or LESS.
  void Print(std::ostream&) const; //The const is even included in the function declarations.
  void Initialize(int number); //Initialize is like a setter function, but what's important is that it's initializing a value for EVERY value in the array.
private:
  int value; //ItemTypes only have ONE member variable.
}; //End of ItemType.h
