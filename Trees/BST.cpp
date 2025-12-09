#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    size = 0;
    root = nullptr;
}
int BST::GetSize() {
    return size;
}

void BST::insert(int val) {
    insertHelper(val, root);
}
void BST::insertHelper(int val, Node* root) {
    if (root == nullptr) {
        Node* newNode = new Node(val);
        size++;
        return;
    }
    if (val > root->value)
    {
        insertHelper(val, root->right);
    }
    else {
        insertHelper(val, root->left);
    }
}
bool BST::search(int val) {
    return searchHelper(val, root);
}

bool BST::searchHelper(int val, Node* root) {
    if (val == root->value)
    {
        cout << "Value has been found.";
        return true;

    }
    else if (val > root->value)
    {
        val
    }
}
