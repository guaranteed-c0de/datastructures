#include <iostream>
#include <string>
#include "List.h"
#ifndef UNSORTED_ARRAY_H
#define UNSORTED_ARRAY_H
using namespace std;
class UnsortedArray: public List {
    public:
        UnsortedArray()
        {
            length = 0;
        }
       virtual void Insert(ItemType* item) override{
            
       }
        int GetLength() const{
            return length;
        }
    private:
        int length;
};
#endif //UNSORTED_ARRAY_H

