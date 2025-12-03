#include "Tree.h"

int main() {
    TreeType Test;
    Test.InsertKeyValue("Morehouse", 1867);
    Test.InsertKeyValue("Spelman", 1881);
    Test.InsertKeyValue("Clark", 1988);
    Test.InsertKeyValue("Howard", 1867);
    Test.InsertKeyValue("Hampton", 1868);
    Test.InsertKeyValue("Tuskegee", 1881);
    Test.InsertKeyValue("Florida A&M", 1887);
    Test.InsertKeyValue("Xavier", 1831);
    Test.InsertKeyValue("Morgan State", 1867);
    Test.InsertKeyValue("Dillard", 1869);
    Test.AddKeyValue();
    Test.GetLength();
    Test.SearchKey();
    Test.DeleteNode();
    Test.GetLength();
    return 0;
}