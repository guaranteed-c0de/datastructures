#include "HeapMaster.h"

int main() {
    HeapMaster<int, 100005, std::greater<int>> Face;

    for (int i = 1; i <= 20; i++)
    {
        Face.push(i);
    }
    Face.printArray();

    Face.top();
    int x = 0;
    while (x < 10)
    {
        Face.pop();
        x++;
    }
    Face.printArray();
}