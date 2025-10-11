#include "SortedLinkedList.h"
#include "MediaPlayer.h"
#include "Playlist.h"
#include <iostream>
using namespace std;

int main() {
   Song song1("Cozy Coffeehouse", "Lunar Years", 110, "cozycoffeehouse.mp3");
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
   return 0;
}