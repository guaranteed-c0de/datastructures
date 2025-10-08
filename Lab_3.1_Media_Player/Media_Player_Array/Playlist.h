#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "Unsorted_linked_list.h"
class Playlist : public UnsortedList {
    public:
    void addSong(const Song& song) {
        
    }
    void removeSong(const std::string& title);
    Song* getCurrentSong(); //Returns current playing song.
    void nextSong(); //Move to next in list.
    void previousSong(); //Move to previous
    //Add sorting method if extending to sorted list.
    void sortByTitle();
};

#endif //PLAYLIST_H