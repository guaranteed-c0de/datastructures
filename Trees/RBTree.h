#ifndef RB_TREE_H
#define RB_TREE_H

#include "BST.h"

class RBTree : public BST {
public:
    RBTree() : BST() {}

    // Override entire insert, because RB insert process differs
    void insert(int val) override;

protected:
    enum Color { RED, BLACK };

    // ===== Derived Node Type =====
    struct RBNode : public Node {
        Color color;
        RBNode(int v) : Node(v), color(RED) {}
    };

    // Cast root to RBNode*
    RBNode*& asRB(Node*& node) { return reinterpret_cast<RBNode*&>(node); }

    // Helper functions
    RBNode* bstInsert(int val);  // normal BST insert but using RBNode
    void fixInsert(RBNode* node);

    // Rotations (return RBNode*)
    RBNode* rotateLeft(RBNode* node);
    RBNode* rotateRight(RBNode* node);
};

#endif