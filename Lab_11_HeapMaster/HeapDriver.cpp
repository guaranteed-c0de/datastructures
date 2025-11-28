#include "HeapMaster.h"

int main() {
    HeapMaster<int> Face;

    for (int i = 1; i <= 20; i++)
    {
        Face.push(i);
    }
    Face.printArray();
}