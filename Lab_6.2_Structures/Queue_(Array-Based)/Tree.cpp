#include "ArrayQueue.h"

template <typename T>
void Tree <T>:: Traversal(TreeNode* root) {
    if (root == nullptr)
    {
        return;
    }
    
    Q.Enqueue(root);

}