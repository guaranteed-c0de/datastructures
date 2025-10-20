#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "SortedArray.h"
#include "UnsortedArray.h"
#include <iostream>
class Playlist {
  public:
    void addSong(const Song& song) {
        list->Insert(new Song(song));
        
    }
    Playlist(List* implementation) : list(implementation), y(-1){}
    Playlist()
    {
        list = new SortedArray();
        y = -1;
    }
    ~Playlist() {delete list;}
    
    void removeSong(const std::string& title) {
        Song temp(title, "", 0, "");
        list->Remove(temp);
    }
    Song* getCurrentSong() {
        if(y < 0 || y >=  list->GetNumberOfItems())
        {
            return nullptr;
        }
        else {
            return dynamic_cast<Song*>(list -> GetItem(y)); //What does dynamic_cast mean? How does this all return a Song* variable?
        }
    } //Returns current playing song.
    void nextSong() {
        if(y != 0 && y != list->GetNumberOfItems())
        {
            y +=1;
        }
        else {
            y = 0;
        }
    } //Move to next in list.
    void previousSong() {
        if (y == 0) 
        {
          y = list->GetNumberOfItems(); //Returns the final item in the list.
        }
        else {
            //Time to find the previous one..
            y -=1;
        }
    } //Move to previous
    //Add sorting method if extending to sorted list.
    void sortByTitle() {
     y = 0;
        
     while (y!= list->GetNumberOfItems()) {
        Song* song = dynamic_cast<Song*>(list->GetItem(y));
        if(song != nullptr) {
            std::cout << song->title << endl;
        }
        y += 1;
        
     }
    }

    void mergeSortedPlaylists(Playlist& other) {
        SortedArray* thisList = dynamic_cast<SortedArray*>(this->list);
        SortedArray* otherList = dynamic_cast<SortedArray*>(other.list);
        if(!thisList || !otherList)
        {
            std::cout << "Invalid. Both lists must be sorted.";
        }
        thisList->Merge(*otherList);
    }

    int GetLength() {
        return list->GetNumberOfItems();
    }
    void searchPlaylist() {
        string artist_last_name;
        cout << "Search for a song by the last name of the artist.\n";
        cin >> artist_last_name;
        if(artist_last_name != "Years" || artist_last_name != "Bosman" || artist_last_name != "Vital" || artist_last_name != "Delays")
        {
            cout << "Sorry. That is not an artist of a song you can add to your playlist." << endl;
        }

    }
private:
   List* list;
   int y;
};

#endif //PLAYLIST_H