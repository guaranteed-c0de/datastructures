#include "Tree.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

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
auto start = high_resolution_clock::now();
Test.InsertKeyValue("Harvard", 1636);   
auto end = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(end - start);
cout << "Insertion took " << duration.count() << " microseconds.\n";
    return 0;
}