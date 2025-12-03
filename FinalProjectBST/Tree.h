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
        TreeType(const TreeType& originalTree);
        void operator = (TreeType& originalTree);
        void MakeEmpty();
        bool IsEmpty() const;
        int SearchKey(std::string name) const;
        void InsertKeyValue(std::string& key, int value);
        void InsertHelper(TreeNode*& loc, std::string& key, int value);
        int GetLength() const;
        void DeleteNode(std::string name);
        void DeleteHelper(TreeNode*& loc, std::string name);
    private:
        TreeNode* root;
        int length;
};