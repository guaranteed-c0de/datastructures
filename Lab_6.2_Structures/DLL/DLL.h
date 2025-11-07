
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
    int length;
    DLL();
    void insertHead(DLLNode*& head, int val); //List is empty.
    void insertTail(DLLNode*& tail, int val);
    bool IsEmpty();
    void DeleteHead(DLLNode* & head, DLLNode* & tail); //List is already empty. List has exactly 1 node.
    void DeleteTail(DLLNode* & head, DLLNode* & tail); //List is already empty. List has exactly 1 node.
    void InsertAfter(DLLNode* node, int val);
    void DeleteNode(DLLNode* node);
    void Reverse(DLLNode*& head, DLLNode*& tail);
    DLLNode* Middle(DLLNode* head);
    bool HasCycle(DLLNode* head);
};
