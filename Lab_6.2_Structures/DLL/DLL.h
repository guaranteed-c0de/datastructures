
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
    void insertHead(int val); //List is empty.
    void insertTail(int val);
    bool IsEmpty();
    void DeleteHead(); //List is already empty. List has exactly 1 node.
    void DeleteTail(); //List is already empty. List has exactly 1 node.
    void InsertAfter(DLLNode* node, int val);
    void DeleteNode(DLLNode* node);
    void Reverse(DLLNode*& head, DLLNode*& tail);
    DLLNode* Middle(DLLNode* head);
    bool HasCycle(DLLNode* head);
    void Print();
};
