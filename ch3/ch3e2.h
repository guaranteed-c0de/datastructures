#ifndef EXAMPLES_CH3E2_H
#define EXAMPLES_CH3E2_H

class ItemType{

public:
    int key;
    ItemType() {
        key = 0;
    }
    ItemType(int k): key(k) {}
    int compareTo(ItemType& other) {
        if (key == other.key) return 0;
         return key < other.key ? -1 : 1;
        
    } //How does "next" work?

};

struct NodeType {
    ItemType item;
    NodeType* next;
};

class UnsortedList {
    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
    public:
        UnsortedList() {
            listData = nullptr;
            length = 0;
            currentPos = nullptr;
        }
        ~UnsortedList() {
            NodeType* tempPtr;
            while (listData != nullptr) {
                tempPtr = listData;
                listData = listData ->next;
                delete tempPtr;
            }
        }
        void Insert(ItemType item) {
            NodeType* location = new NodeType; //Allocate memory. It's a pointer.
            location-> item = item; //Copy? Dot notations are for dereferencing. Pointers require arrows.
            location->next = listData; //Point to new node?
            listData = location; //Why location?
            length++; //Make the adjustments as needed. Trace it through drawing... Length increases by one.
        }
        void ResetList();
        bool isEmpty();
        bool isFull(); 
        int Length() const;
        void DeleteItem(ItemType item) { //We need both pointers. I assume because only item1 "knows" where item 2 is.
            currentPos = listData; //Why would listData be equal to the nullptr? What condition would make that occur?
            NodeType* prev = currentPos;
            if (currentPos && currentPos -> item.compareTo(& item) == 0)
            {
                listData = currentPos ->next;
                delete currentPos; //We need a temporary pointer variable to avoid memory leak....
                length--;
            } //What is listData? location?
                //curentPos = listData; This doesn't make cuurentPos
            while (currentPos && currentPos->next) { //Say that the previous node is going to be equal to the current one.
                prev = currentPos;
                if (currentPos-> next -> item.compareTo({&}item)==0) {
                    prev-> next = //What does next do? What does new do? CURRENT next?
                    //What do these pointers represent?
                }
            }
        }
};

#endif //EXAMPLES_CH3E2_H