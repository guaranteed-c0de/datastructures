#include <iostream>
#include <string>
#include "ItemType.h"
#ifndef UNSORTED_ARRAY_H
#define UNSORTED_ARRAY_H
using namespace std;
class UnsortedArray {
    public:
        UnsortedArray()
        {
            length = 0;
        }
        bool IsFull() const {
            return (length == MAX_ITEMS);
        }
        int GetLength() const{
            return length;
        }
    private:
        int length;
};
#endif //UNSORTED_ARRAY_H

