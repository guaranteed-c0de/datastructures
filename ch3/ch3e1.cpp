class ItemType
{

    /*data*/

    public:
        int key;
        ItemType(int k): key(k){}

        int CompareTo(ItemType& other){ //Pass it as a reference.

            if (key == other.key){ //String.compareto
                return 0;
            }
            else if (key < other.key) { //The book tried to split the operations.
                return -1;
            }
            else {
                return 1;
            }
        }
};
const int MAX_ITEMS = 122;
class UnsortedList {
    private:
        ItemType data[MAX_ITEMS];
        int length = 0;
        int currPos = -1;
    public:
        UnsortedList() = default;

        ~UnsortedList()
        {
            delete[] data;
        }

        void Insert(ItemType item) {
                if (length < MAX_ITEMS + 1)
                {
                    data[length++] = item; //C++ doesn't check for array indexes.
                }
        }
        int Length() const {
            return length;
        }   
        
        bool isEmpty() {
            return length == 0; //That bcomes a boolean.
        }

        bool isFull() {
            return length == MAX_ITEMS;
        }

        void ResetList() {
            currPos = -1;
        }

        void DeleteItem(ItemType item)
        {
            for (int i = 0; i < length; i++)
            {
                if (data[i].CompareTo(item) == 0)
                {
                    for (int j = i; j < length - 1; j++)
                    {
                        data[j] = data[j + 1];
                    }
                    length--; //We are shifting everything back.  O(n) = A * n. O(n^2) = A * (n^2).

                } //If you are going to avoid this solution.... null length--; Wouldn't it be confusing because you'd have to remember which space IS null.
            }
        }
};