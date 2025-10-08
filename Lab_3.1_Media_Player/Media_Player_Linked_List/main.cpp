#include "SortedLinkedList.h"
#include "MediaPlayer.h"
#include "Playlist.h"

int main() {
   Song song1("Cozy Coffeehouse", "Lunar Years", 110, "cozycoffeehouse.mp3");
   Song song2("Sleepless", "Diffie Bosman", 154, "sleepless.mp3");
   Song song3("Melancholy Lull", "Vital", 136, "melancholylull.mp3");
   Song song4("Prism", "Theatre of Delays", 221, "prism.mp3");

   Playlist spl1(new SortedList());
   return 0;
}