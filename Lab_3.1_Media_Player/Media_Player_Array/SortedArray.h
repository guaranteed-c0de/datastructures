#include <iostream>
#include <string>
#include "List.h"
#include "Song.h"
#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H
using namespace std;
class SortedArray: public List {
    public:
        virtual void Insert(ItemType* item) override{
            currentPosition = 0;
            bool MoreToSearch = (currentPosition == length);

            if (!MoreToSearch || item -> LessThan(*(items_array[0])))
            {
                for (int j = length; j > 0; j--)
                {
                    items_array[j] = items_array[j - 1];
                }
                items_array[0] = item;
            }
            else {
               int i = 0;
                while (i <= length - 1 && item->LessThan(*(items_array[i + 1])))
                {
                    i++;
                }
                 for (int j = length; j > 0; j--)
                {
                    items_array[j] = items_array[j - 1];
                }
                items_array[i] = item;
            }
            length++;
       }
        virtual void Remove(ItemType& item) override {
        for (int i = 0; i < length; i++) {
            if(items_array[i] -> CompareTo(item)) {
                delete items_array[i];
                items_array[i] = items_array[length - 1];
                length--;
                return;
            }
        }
        
       }
        SortedArray()
        {
            length = 0;
        }
       
      
       virtual bool IsPresent(const ItemType& item) const {
        for (int i = 0; i < length; i++) {
            if(items_array[i] -> CompareTo(item)) {
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
                items_array[i] -> Print(std::cout);
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
             for (int i = 0; i < length; i++) {
        delete items_array[i];
    }
            length = 0;
        }
        virtual ItemType* GetItem(int index) {
            if (index < 0 || index >= length)
            {
                return nullptr;
            }
            else {
                return items_array[index];
            }
        }
        void Merge(SortedArray& other)
        {
            ItemType* merged[MAX_ITEMS];  // temporary array to hold merged items
    int i = 0; // index for this->items
    int j = 0; // index for other.items
    int k = 0; // index for merged[]

    //  Merge until one list is exhausted
    while (i < this->length && j < other.length) {
        if (this->items_array[i]->LessThan(*other.items_array[j])) {
            merged[k++] = this->items_array[i++];
        } else {
            merged[k++] = other.items_array[j++];
        }
    }

    // Copy remaining elements
    while (i < this->length) {
        merged[k++] = this->items_array[i++];
    }
    while (j < other.length) {
        merged[k++] = other.items_array[j++];
    }

    // Copy merged array back into this->items
    for (int n = 0; n < k; n++) {
        this->items_array[n] = merged[n];
    }

    //  Update the length
    this->length = k;

    // Empty the other array
    other.length = 0;
        }
        ~SortedArray()
        {
            Clear();
        }
    private:
        const int MAX_ITEMS = 10000;
        int length;
        ItemType* items_array[MAX_ITEMS];
        int currentPosition;
};
#endif //SORTED_ARRAY_H