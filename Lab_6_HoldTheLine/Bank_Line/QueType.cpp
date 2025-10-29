#include "QueType.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  length = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  length = 0;
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
    length++;
  }
}

void QueType::Dequeue()
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    length--;
  }
}
ItemType QueType :: GenerateItem() {
srand(time(0)); 
int number = (rand() % 26) + 1;
ItemType name;
if (number == 1) {name = 'A';}
else if (number == 2) {name = 'B';}
else if (number == 3) {name = 'C';}
else if (number == 4) {name = 'D';}
else if (number == 5) {name = 'E';}
else if (number == 6) {name = 'F';}
else if (number == 7) {name = 'G';}
else if (number == 8) {name = 'H';}
else if (number == 9) {name = 'I';}
else if (number == 10) {name = 'J';}
else if (number == 11) {name = 'K';}
else if (number == 12) {name = 'L';}
else if (number == 13) {name = 'M';}
else if (number == 14) {name = 'N';}
else if (number == 15) {name = 'O';}
else if (number == 16) {name = 'P';}
else if (number == 17) {name = 'Q';}
else if (number == 18) {name = 'R';}
else if (number == 19) {name = 'S';}
else if (number == 20) {name = 'T';}
else if (number == 21) {name = 'U';}
else if (number == 22) {name = 'V';}
else if (number == 23) {name = 'W';}
else if (number == 24) {name = 'X';}
else if (number == 25) {name = 'Y';}
else if (number == 26) {name = 'Z';}
    return name;
}
int QueType:: GetLength() {
  return length;
}
int QueType:: GetFront() {
  return front;
}
void QueType:: DisplayQueue()
{
  int current = front;
  for (int i = 0; i < length; i++)
  {
    cout << items[current%maxQue] << "\t";
    maxQue++;
  }
}
