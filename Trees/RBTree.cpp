#include "RBTree.h"
RBTree::RBNode* RBTree::bstInsert(int val) {
    // If tree is empty
    if (root == nullptr) {
        root = new RBNode(val);
        return static_cast<RBNode*>(root);
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (val < current->value)
            current = current->left;
        else
            current = current->right;
    }

    RBNode* newNode = new RBNode(val);
    newNode->color = RED;

    if (val < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    // Track parent
    newNode->parent = static_cast<RBNode*>(parent);

    return newNode;
}

void RBTree::fixInsert(RBNode* node) {
    while (node != root && node->parent->color == RED) {

        RBNode* parent = node->parent;
        RBNode* grand = parent->parent;

        // Parent is left child
        if (parent == grand->left) {
            RBNode* uncle = dynamic_cast<RBNode*>(grand->right);

            // Case 2: Parent and uncle red
            if (uncle && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                node = grand;
            }
            else {
                // Case 3: Left-Right
                if (node == parent->right) {
                    node = parent;
                    rotateLeft(node);
                }
                // Case 3: Left-Left
                parent->color = BLACK;
                grand->color = RED;
                rotateRight(grand);
            }
        }

        // Parent is right child (mirror cases)
        else {
            RBNode* uncle = dynamic_cast<RBNode*>(grand->left);

            if (uncle && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                node = grand;
            }
            else {
                if (node == parent->left) {
                    node = parent;
                    rotateRight(node);
                }
                parent->color = BLACK;
                grand->color = RED;
                rotateLeft(grand);
            }
        }
    }

    // Always ensure the root is black
    static_cast<RBNode*>(root)->color = BLACK;
}