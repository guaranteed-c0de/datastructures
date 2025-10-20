#include <iostream>
#include <string>
#include "List.h"
#include "Song.h"
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
    
            if (length < MAX_ITEMS) {
                items[length++] = item;
            }
       }
       virtual void Remove(ItemType& item) override {
        for (int i = 0; i < length; i++) {
            if(items[i] -> CompareTo(item)) {
                delete items[i];
                items[i] = items[length - 1];
                length--;
                return;
            }
        }
        
       }
       virtual bool IsPresent(const ItemType& item) const {
        for (int i = 0; i < length; i++) {
            if(items[i] -> CompareTo(item)) {
                return true;
            }
                
        }
        return false;
       }
       virtual void ListItems() const override {
        if (length == 0)
        {
            std::cout << "List is empty\n";
        }
        else {
            for (int i = 0; i < length; i++)
            {
                items[i] -> Print(std::cout);
                std:: cout << endl;
            }
        }
       }
       virtual bool IsEmpty() const override {
        return length == 0;
       }


       virtual int GetNumberOfItems() const override{
            return length;
        }
        virtual void Clear() override {
            length = 0;
        }
        ~UnsortedArray()
        {
            Clear();
        }
    private:
        inline static const int MAX_ITEMS = 10000;
        int length;
        ItemType* items[MAX_ITEMS];
        int currentPosition;
        
};
#endif //UNSORTED_ARRAY_H

