#include "Tree.h"
#include <stdexcept>
using namespace std;
int TreeType::SearchKey(string name) const {
TreeNode* location = root;
    while (location && location->key != name)
    {
        if (location->key > name)
        {
            location = location->left;
        }
        else {
            location = location->right;
        }
        if (location)
        {
            return location->value;
        }
        else {
            throw std:: out_of_range("Name does not match any key.\n");
        }
    }
}

void TreeType::InsertKeyValue(string& key, int value) {
    InsertHelper(root, key, value);
}

void TreeType::InsertHelper(TreeNode*& loc, string& key, int value) {
if (loc == nullptr)
{
    loc = new TreeNode(key, value);
    length++;
    return;
}
if (key < loc->key)
{
    InsertHelper(loc->left, key, value);
}
else if (key > loc->key) {
    InsertHelper(loc->right, key, value);
}
else {
    cout << "A value already exists for " << key << ".\n";
    cout << "Do you want to update it (Type Y or N)?\n";
    char response;
    cin >> response;
    if (response == 'Y' || response == 'y')
    {
        loc->value = value;
        cout << "\nValue has been updated.\n";
        return;
    }
    return;
}
}

void TreeType:: DeleteNode(string name) {
    if (IsEmpty())
    {
        return;
    }

    DeleteHelper(root, name);
}

void TreeType:: DeleteHelper(TreeNode*& loc, string name) {
    if (loc == nullptr)
    {
        throw std::out_of_range("Key does not match any saved name.\n");
        return;
    }
    if (name < loc->key)
{
   
    DeleteHelper(loc->left, name);
}
else if (name > loc->key) {
    
    DeleteHelper(loc->right, name);
}
else {
    if (!loc->left && !loc->right) {
       
        delete loc;
        loc = nullptr;
        length--;
    }
    else if ((loc->left && !loc->right) || (!loc->left && loc->right))
    {
        TreeNode* temp = loc;
        if (loc->left)
        {
            loc = loc->left;
            delete temp;
            length--;
            return;
        }
        
        loc = loc->right;
        delete temp;
        length--;
        return;
    }
    else {
         TreeNode* successor = FindMin(loc->right);

            
            loc->key = successor->key;
            loc->value = successor->value;

            DeleteHelper(loc->right, successor->key);
    }
}
}
TreeNode* FindMin(TreeNode* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}