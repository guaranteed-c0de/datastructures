#ifndef BST_H
#define BST_H

class BST {
    protected:
struct Node {
Node* left;
Node* right;
int value;
Node(int val) : value(val), left(nullptr), right(nullptr) {};
};

int size;
Node* root;

public:
virtual void insert(int val);
virtual void insertHelper(int val, Node*& root);
virtual void remove(int val, Node* root);
Node* findMin(Node* loc);
bool isEmpty();
bool search(int val);
bool searchHelper(int val, Node* root);
int GetSize();
BST();

};
#endif //BST_H