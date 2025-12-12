#include <iostream>
#include <string>
#include <cstring>
struct TreeNode {
     std::string key;
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(std::string k, int v)
    : key(k), value(v), left(nullptr), right(nullptr) {}
};

class TreeType {
    public:
        TreeType();
        ~TreeType();
        void EmptyHelper(TreeNode* root); //Recursive function that helps with the Deconstructor
        TreeType(const TreeType& originalTree);
        void operator = (TreeType& originalTree);
        void MakeEmpty();
        bool IsEmpty() const;
        int SearchKey() const; //User types in the search key.
        int SearchKey2(const std::string& key); //Programmer inserts the search key.
        void InsertKeyValue(const std::string& key, int value);
        void InsertHelper(TreeNode*& loc, const std::string& key, int value);
        int GetLength() const; //Prints out the length as well as returns the length as an int value.
        void DeleteNode(); //Usert types the search key they would want to delete.
        void DeleteNode2(const std::string& key); //Programmer inserts the key of the node to be deleted.
        void DeleteHelper(TreeNode*& loc, std::string& name);
        void AddKeyValue(); //User types in the key and value they would add into the tree.
        TreeNode* FindMin(TreeNode* node);
    private:
        TreeNode* root;
        int length;
};