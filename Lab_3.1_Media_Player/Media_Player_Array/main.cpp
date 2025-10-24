#include "SortedArray.h"
#include "MediaPlayer.h"
#include "Playlist.h"
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
void testMergeTime(int n) {
    Playlist list1, list2;
    cout << "Hello World!";
    
    for (int i = 0; i < n; i++) {
        Song s1("Title" + to_string(i), "Artist" + to_string(i), 200, "path");
        Song s2("Title" + to_string(n - i), "Artist" + to_string(n - i), 200, "path");
        list1.addSong(s1);
        list2.addSong(s2);
    }

    auto start = high_resolution_clock::now();

    list1.mergeSortedPlaylists(list2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Merging " << n << " songs took "
         << duration.count() << " ms." << endl;
}
int main() {
   testMergeTime(100);
   testMergeTime(1000);
   testMergeTime(10000);
   return 0;
}