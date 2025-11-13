struct TreeNode {
    TreeNode* left;
    TreeNode *right;
    int info;
};

class TreeType {
    private:
        TreeNode *root;
    public:
        TreeType() : root(nullptr) {

        }

        ~TreeType() {

        }
        bool GetItem(int item) {
            TreeNode* node = root;
            while (node != nullptr && item != node->info) {
                node = item < node->info ? node->left : node->right;
            }
            return node != nullptr;
        }
        bool GetItemrec(int item)
        {
            bool found = false;
            Retreive(root, item, found);
            return found;
        }
        void Retreive(TreeNode *node, int item, bool &found) {
            if (node == nullptr) {
                found = false;
            }
            else if (item < node->info) {
                Retreive(node->left, item, found);
            }
            else if (item > node->info) {
                Retreive(node->right, item, found);
            }
        }
    void PutItem(int item) {
        Insert(root, item);
    }
    void Insert(TreeNode*& node, int item) {
        if (node == nullptr) {
            node = new TreeNode;
            node->info = item;
            node->left = nullptr;
            node->right = nullptr;
        }
        else if (item < node->info) {
            Insert(node->left, item);
        }
        else {
            Insert(node ->right, item);
        }
    }
    bool GetItemrec(int item) {
        bool found = false;
        Retrieve(root, item, found);
        return found;
    }

    bool GetItem(int item) {
        TreeNode* node = root;
        while (node != nullptr && item != node->info) {
            node = item < node->info ? node->left : node->right;
        }
    }
};

int main() {
    TreeType tree;
    tree.PutItem(10);
    tree.PutItem(5);
    tree.PutItem(15);
    tree.GetItem(10);
    return 0;
}

