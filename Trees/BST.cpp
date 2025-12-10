#include "BST.h"
#include <iostream>
#include <stdexcept>
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
void BST::insertHelper(int val, Node*& root) {
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
        cout << "Value has been found.\n";
        return true;
    }
    else if (root == nullptr)
    {
        cout << "Value not found.\n";
        return false;
    }
    else if (val > root->value)
    {
        searchHelper(val, root->right);
    }
    else {
        searchHelper(val, root->left);
    }
}

void BST::remove(int val, Node* root) {
    if (isEmpty()) {
        throw std::underflow_error("Tree is empty.\n");
    }
    else if (root == nullptr) {
        throw std::underflow_error("Value not found.\n");
    }
    if (val > root->value) {
        remove(val, root->right);
    }
    else if (val < root->value) {
        remove(val, root->left);
    }
    else {
        if (root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            size--;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
            size--;
        }
        else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            remove(temp->value, root->right);
        }
    }
}
bool BST::isEmpty() {
    return size == 0;
}

Node* BST::findMin(Node* loc) {
    while (loc->left != nullptr) {
        loc = loc->left;
    }
    return loc;
}
