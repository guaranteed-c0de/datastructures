

class DLL {
public:
    struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};
    DLLNode* head;
    DLLNode* tail;
    void insertHead(DLLNode*& head, int val);
    
};
