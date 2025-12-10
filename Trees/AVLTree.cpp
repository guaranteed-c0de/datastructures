#include "AVLTree.h"

AVLTree::AVLTree() : BST() {}

void AVLTree::insert(int val) {
    insertHelper(val, root);
}

void AVLTree::insertHelper(int val, Node*& node) {
    // TODO: implement AVL insert logic
    // For now, just call BST version to remove the warning:
    BST::insertHelper(val, node);

    // Later you will add AVL logic here (height update, rotations)
}

int AVLTree::getBalance(Node* node) {
    // TODO
    return 0;
}

BST::Node* AVLTree::rotateLeft(Node* y) {
    // TODO
    return y;
}

BST::Node* AVLTree::rotateRight(Node* T) {
    Node* S = T->left;
    Node* B = S->right;
    S->right = T;
    T->left = B;
    return S;
}