#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "List.h"
#include "UnsortedLinkedList.h"
#include "SortedLinkedList.h"
class Playlist : public UnsortedList {
    public:
    void addSong(const Song& song) {
        list->Insert(new Song(song));
    }
    Playlist(List* implementation) : list(implementation), currentsong(nullptr){}
    Playlist()
    {
        list = nullptr;
        currentsong = nullptr;
    }
    ~Playlist() {delete list;}
    void removeSong(const std::string& title) {
        Song temp(title, "", 0, "");
        Remove(temp);
    }
    Song* getCurrentSong() {
        if(currentsong == nullptr)
        {
            return nullptr;
        }
        else {
            return dynamic_cast<Song*>(currentsong->item); //What does dynamic_cast mean? How does this all return a Song* variable?
        }
    } //Returns current playing song.
    void nextSong() {
        if(currentsong != nullptr && currentsong->next != nullptr)
        {
            currentsong = currentsong->next;
        }
        else {
            currentsong = listData;
        }
    } //Move to next in list.
    void previousSong() {
        if (currentsong == listData || currentsong == nullptr) 
        {
            Node* temp = listData;
            while (temp != nullptr && temp->next != nullptr)
            {
                temp = temp -> next;
            }
             currentsong = temp;
        }
        else {
            //Time to find the previous one..
            Node* temp = listData;
            while(temp != listData && temp ->next != currentsong)
            temp = temp->next;
            currentsong = temp;
        }
    } //Move to previous
    //Add sorting method if extending to sorted list.
    void sortByTitle() {
        list -> PrintTitlesOnly();
    }

    void mergeSortedPlaylists(Playlist& other) {
            Node temp(nullptr); // temporary head for result
            Node* tail = &temp; // keeps track of end of merged list
            Node* playlistptr1 = this->listData;
            Node* playlistptr2 = other.listData;

            while (playlistptr1 != nullptr && playlistptr2 != nullptr)
            {
                if(playlistptr1->item->LessThan(*(playlistptr2->item)))
                {
                    tail->next = playlistptr1;
                    playlistptr1 = playlistptr1 ->next;
                }
                else {
                    tail-> next = playlistptr2;
                    playlistptr2 = playlistptr2->next;
                }
                tail = tail->next;
            }
            //Add extra nodes.
            tail->next = (playlistptr1 != nullptr) ? playlistptr1: playlistptr2;
            

            this->listData = temp.next;
            this->length += other.length;

            //Empty the 'other' playlist

            other.listData = nullptr;
            other.length = 0;
    }
private:
    List* list;
    Node* currentsong;
};

#endif //PLAYLIST_H