const int MAX_ITEMS = 50;
class ItemType {

    public:
        virtual ~ItemType() = default;
        virtual bool CompareTo (const ItemType& other) const = 0; //Equality comparison.
        virtual bool LessThan( const ItemType& other) const = 0; //For sorting
        virtual void Print(ostream& out) const = 0;
};