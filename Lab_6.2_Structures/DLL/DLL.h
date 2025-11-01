
   struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};
class DLL {
public:
 
    DLLNode* head;
    DLLNode* tail;
    void insertHead(DLLNode*& head, int val);
    void insertTail(DLLNode*& tail, int val);
    bool IsEmpty();
};
