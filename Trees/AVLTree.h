#ifndef AVLTREE_H
#define AVLTREE_H
#include "BST.h"

class AVLTree: public BST {
AVLTree() : BST() {}

void insert(int val) override;
virtual void insertHelper(int val, Node*& root);

protected:
int getBalance(Node* node);
Node* rotateLeft(Node* T);
Node* rotateRight(Node* T);
Node* RotateRightLeft(Node* T);
Node* RotateLeftRight(Node* T);
void InOrder(Node* tree);
};

#endif //AVLTREE_H