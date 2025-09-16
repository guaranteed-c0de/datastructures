#ifndef EXAMPLE_CH3E1_H
#define EXAMPLE_CH3E1_H
class ItemType
{
public:
  int key;
ItemType() {
  key = 0;
}

}
UnsortedList(int MAX_ITEMS = 100) {
  capacity = MAX_ITEMS;
  data = new ItemType[capacity];
  length = 0;
  currPos = -1;
}

class UnsortedList{
private:
int capacity;
ItemType* data
void DisplayInReverse() {
  for (int i; = length - 1; i--) {
    cout << data[i].key << std::endl;
  }
}
};
