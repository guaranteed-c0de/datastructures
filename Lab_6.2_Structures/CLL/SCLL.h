#include <utility>
class SCLL {
public:

struct SCLLNode {
    int val;
    SCLLNode* next;
    SCLLNode(int v) : val(v), next(nullptr) {}
};
SCLLNode* head;
SCLLNode* tail;
int length;
SCLL();
void InsertHead(int val);
void InsertTail(int val);
void DeleteHead();
void DeleteLastNode();
int Josephus(int k);
std:: pair<SCLLNode*, SCLLNode*> Split();
int CycleLength();
void SortedInsert(int val);
void Print();
};