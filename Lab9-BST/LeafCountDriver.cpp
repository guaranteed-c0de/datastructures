#include <iostream>
using namespace std;
#include "TreeType.h"


int main() {
    TreeType Oak;
   // Oak.PutItem('X');
  //  Oak.PutItem('Y');
    Oak.PutItem('W');
   cout << "There are " << Oak.GetLength() << " nodes in the tree.\n";
   cout << Oak.LeafCount() << " of these nodes are leaves.\n";
    return 0;
}
//Edge cases: 1 node (1 leaf), 0 nodes (0 leaves), 3 nodes (1 leaf), 3 nodes (2 leaves), 7 nodes (4 leaves).