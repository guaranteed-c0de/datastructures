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
     auto start = high_resolution_clock::now();
    for (int i = 1; i <= MILLION; i++) { //Pushes 1 million elements.
        TestPush.push(Five(gen));
    }
     auto end = high_resolution_clock::now();
  
    auto duration = duration_cast<nanoseconds>(end - start);

    cout << "Inserts took " << duration.count() << " nanoseconds.\n"; 
    
     
    int arr[1000000];

    for (int i = 0; i<1000000; i++)
    {
        arr[i] = Five(gen);
    }
    TestBuild.BuildHeap(arr, 1000000);
}