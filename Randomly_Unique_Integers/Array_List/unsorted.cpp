// Implementation file for Unsorted.h

#include "unsorted.h" //unsorted.h has ItemType.h, so it isn't necessary for unsorted.cpp to include it too.

UnsortedType::UnsortedType() //This is a default constructor for legnth.
{
  length = 0; //But for arrays, length will eventually become the MAX_ITEMS.
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS); 
}
int UnsortedType::GetLength() const //This is an accessor for length.
{
  return length;
}

ItemType UnsortedType::GetItem(ItemType item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
  bool moreToSearch;
  int location = 0;
  found = false; //Starts as false. Ideally we want it to remain false, so we can isolate the conditions where the boolean can change to true.

  moreToSearch = (location < length);

  while (moreToSearch && !found) //While the program is not at the end of the array, and there is no value.
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++; //location moves to the next index.
                     moreToSearch = (location < length); 
                     break; //gets out of the while loop.
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
  return item;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}
void UnsortedType::PutItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL) //In this case, location will only increase.
    location++;

  info[location] = info[length - 1]; //At this point, the location of the index is at the desired spot where an item will be deleted.
  length--; //This deletes the item by putting the second to last item in its place. The length of the array is decreased by 1.
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1; //-1 is the value because it is invalid. 
}

ItemType UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}
//End of unsorted.cpp.
