#ifndef BST_H
#define BST_H
struct Node {
Node* left;
Node* right;
int value;
Node(int val) : value(val), left(nullptr), right(nullptr) {};
};
class BST {
private:
int size;
Node* root;
public:
void insert(int val);
void insertHelper(int val, Node* root);
void remove(int val);
bool search(int val);
bool searchHelper(int val, Node* root);
int GetSize();
BST();
};
#endif //BST_H