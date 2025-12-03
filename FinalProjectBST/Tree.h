#include <iostream>
#include <string>
#include <cstring>
struct TreeNode {
    const std::string  key;
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
        int SearchKey(const std::string& name) const;
        void InsertKeyValue(const std::string& key, int value);
        void InsertHelper(TreeNode*& loc, const std::string& key, int value);
        int GetLength() const;
        void DeleteNode(const std::string& name);
        void DeleteHelper(TreeNode*& loc, const std::string& name);
        void AddKeyValue();
        TreeNode* FindMin(TreeNode* node);
    private:
        TreeNode* root;
        int length;
};