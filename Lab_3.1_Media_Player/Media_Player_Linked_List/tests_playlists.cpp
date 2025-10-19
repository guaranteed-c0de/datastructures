#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Playlist.h"
TEST_CASE("Playlist Operations") {
    Playlist p1;
    p1.addSong(Song("Cozy Coffeehouse", "Lunar Years", 110, "cozycoffeehouse.mp3"));
    p1.addSong(Song("Sleepless", "Diffie Bosman", 154, "sleepless.mp3"));
    REQUIRE(p1.GetLength() == 2);
}