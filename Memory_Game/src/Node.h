#include "Card.h"

#ifndef NODE_H
#define NODE_H
struct Node {
    Card data;
    Node* next;
    Node(Card c) : data(c), next(nullptr) {}

};
#endif //NODE_H