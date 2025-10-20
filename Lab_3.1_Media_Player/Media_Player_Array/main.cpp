#include "SortedArray.h"
#include "MediaPlayer.h"
#include "Playlist.h"
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void testMergeTime(int n) {
    Playlist list1, list2;
    
    
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

  /* Song song1("Cozy Coffeehouse", "Lunar Years", 110, "cozycoffeehouse.mp3");
   Song song2("Sleepless", "Diffie Bosman", 154, "sleepless.mp3");
   Song song3("Melancholy Lull", "Vital", 136, "melancholylull.mp3");
   Song song4("Prism", "Theatre of Delays", 221, "prism.mp3");

   Playlist spl1(new SortedLinkedList());
   spl1.addSong(song1);
   spl1.addSong(song2);
   Playlist spl2(new SortedLinkedList());
   spl2.addSong(song3);
   spl2.addSong(song4);
   
   spl1.mergeSortedPlaylists(spl2);
   cout << "Playlist 1\n";

   spl1.sortByTitle();
   //spl2.sortByTitle();
   return 0;*/
   testMergeTime(100);
   testMergeTime(1000);
   testMergeTime(10000);
   return 0;
}