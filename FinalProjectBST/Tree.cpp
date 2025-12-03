#include "Tree.h"
#include <stdexcept>
using namespace std;
TreeType::TreeType() {
    length = 0;
    root = nullptr;
}
TreeType::~TreeType() {
    MakeEmpty();
}

void TreeType::MakeEmpty() {
    EmptyHelper(root);
    root = nullptr;
    length = 0;
}

void TreeType::EmptyHelper(TreeNode* node) {
    if (node != nullptr) {
        EmptyHelper(node->left);   
       EmptyHelper(node->right);  
        delete node;               
    }
}
int TreeType::SearchKey() const {
    string name;
    cout << "Please enter the key identifier.\n";
    cin >> name;
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
        
    }
    if (location)
        {
            cout << "The current value with the name " << name << endl;
            cout << "is " << location->value << "." << endl;
            return location->value;
        }
        else {
            throw std:: out_of_range("Name does not match any key.\n");
        }
}

void TreeType::InsertKeyValue(const string& key, int value) {
    InsertHelper(root, key, value);
}

void TreeType::InsertHelper(TreeNode*& loc, const string& key, int value) {
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

void TreeType:: DeleteNode() {
    if (IsEmpty())
    {
        throw std::underflow_error("Tree is empty. No nodes can be deleted.\n");
        return;
    }
string name;
cout << "Type the key you would like to delete.\n";
cin >>name;
    DeleteHelper(root, name);
}

void TreeType:: DeleteHelper(TreeNode*& loc, const string& name) {
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

            
            string tempKey = successor->key;
            int tempValue = successor->value;

            DeleteHelper(loc->right, successor->key);
            delete loc;
            loc = new TreeNode(tempKey, tempValue);
    }
}
}
TreeNode* TreeType::FindMin(TreeNode* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void TreeType::AddKeyValue() {
     string newName;
     int newValue;
    cout << "\nPlease enter the key identifier and integer value\n."; 
    cout <<  "Use only 1 word for the key identifer and a whole number value.\n";
    cin >> newName;
    cin >> newValue;
    InsertKeyValue(newName, newValue);

}

bool TreeType::IsEmpty() const {
return length == 0;
}
int TreeType::GetLength() const {
    cout << "The current number of elements in the tree is " << length << endl;
    return length;
}