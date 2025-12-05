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
        void EmptyHelper(TreeNode* root);
        TreeType(const TreeType& originalTree);
        void operator = (TreeType& originalTree);
        void MakeEmpty();
        bool IsEmpty() const;
        int SearchKey() const;
        int SearchKey2( std::string& key);
        void InsertKeyValue(const std::string& key, int value);
        void InsertHelper(TreeNode*& loc, const std::string& key, int value);
        int GetLength() const;
        void DeleteNode();
        void DeleteNode2(const std::string& key);
        void DeleteHelper(TreeNode*& loc, std::string& name);
        void AddKeyValue();
        TreeNode* FindMin(TreeNode* node);
    private:
        TreeNode* root;
        int length;
};