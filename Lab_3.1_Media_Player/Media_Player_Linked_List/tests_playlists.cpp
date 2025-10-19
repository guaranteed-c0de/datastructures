#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "Playlist.h"
TEST_CASE("Playlist Operations") {
    Playlist p1;
    Playlist p2;
    p2.addSong(Song("Melancholy Lull", "Vital", 136, "melancholylull.mp3"));
    p1.addSong(Song("Sleepless", "Diffie Bosman", 154, "sleepless.mp3"));
    p1.addSong(Song("Cozy Coffeehouse", "Lunar Years", 110, "cozycoffeehouse.mp3"));
    REQUIRE(p1.GetLength() == 2);
    p1.mergeSortedPlaylists(p2);
    REQUIRE(p1.GetLength() == 3);
}