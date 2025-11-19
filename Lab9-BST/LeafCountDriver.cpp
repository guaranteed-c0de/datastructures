#include <iostream>
using namespace std;
#include "TreeType.h"


int main() {
    TreeType Oak;
    Oak.PutItem('X');
    Oak.PutItem('Y');
    Oak.PutItem('W');
   cout << "There are " << Oak.GetLength() << " nodes.";
   cout << Oak.LeafCount() << " of these nodes are leaves.";
    return 0;
}