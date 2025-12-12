#include "HeapMaster.h"
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <climits>   // for INT_MAX
#include <algorithm>
using namespace std;
using namespace std::chrono;
int main() {
    HeapMaster<int, 1000000, std::greater<int>> TestPush;
   HeapMaster<int, 1000000, std::greater<int>> TestBuild;
   const int MILLION = 1000000;
   std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> Five(1, 10000000);
     
    for (int i = 1; i <= MILLION; i++) { //Pushes 1 million elements.
        TestPush.push(Five(gen));
    }
  
    
     
    int* arr = new int[1000000];

    for (int i = 0; i<1000000; i++)
    {
        arr[i] = Five(gen);
    }
    auto start = high_resolution_clock::now();
    TestBuild.BuildHeap(arr, 1000000);
       auto end = high_resolution_clock::now();
  
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Building heap with an array took " << duration.count() << " microseconds.\n"; 
    return 0;
}