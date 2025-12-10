#ifndef AVLTREE_H
#define AVLTREE_H
#include "BST.h"

class AVLTree: public BST {
AVLTree() : BST() {}

void insert(int val) override;
virtual void insertHelper(int val, Node*& root);

protected:
int getBalance(Node* node);
Node* rotateLeft(Node* y);
Node* rotateRight(Node* T);
};

#endif //AVLTREE_H