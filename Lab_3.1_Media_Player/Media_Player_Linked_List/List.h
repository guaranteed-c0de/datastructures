
#ifndef LIST_H
#define LIST_H

#include "ItemType.h"

class List {
public:
    virtual void Insert(ItemType* item) = 0;
    virtual void Remove(ItemType& item) = 0;
    virtual bool IsPresent(const ItemType& item) const = 0;
    virtual void ListItems() const = 0;
    virtual bool IsEmpty() const = 0;
    virtual int GetLength() const = 0;
    virtual void Clear() = 0;
    virtual void Merge(List* other) = 0;
    virtual ~List() {}
};

#endif //LIST_H
