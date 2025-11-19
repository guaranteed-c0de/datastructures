#include <iostream>
using namespace std;
#include "TreeType.h"


int main() {
    TreeType Oak;
    Oak.PutItem('X');
   cout << "The length is " << Oak.GetLength();
    return 0;
}