#include <iostream>
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
const int MAX_ITEMS = 10000;
class ItemType {

    public:
        virtual ~ItemType() = default;
        virtual bool CompareTo (const ItemType& other) const = 0; //Equality comparison.
        virtual bool LessThan( const ItemType& other) const = 0; //For sorting
        virtual void Print(std::ostream& out) const = 0;
};
#endif //ITEMTYPE_H