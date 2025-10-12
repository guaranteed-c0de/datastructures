#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "List.h"
#include "UnsortedLinkedList.h"
#include "SortedLinkedList.h"
class Playlist {
    public:
    void addSong(const Song& song) {
        list->Insert(new Song(song));
    }
    Playlist(List* implementation) : list(implementation), currentsong(nullptr){}
    Playlist()
    {
        list = new SortedLinkedList();
        currentsong = nullptr;
    }
    ~Playlist() {delete list;}
    void removeSong(const std::string& title) {
        Song temp(title, "", 0, "");
        list->Remove(temp);
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
     Node* currentsong = listData;
     while (currentsong!= nullptr) {
        int i = 1;
        std::cout << "Visiting node..." << i << std::endl;
        Song* song = dynamic_cast<Song*>(currentsong->item);
        if(song != nullptr) {
            std::cout << song->title << endl;
        }
        currentsong = currentsong->next;
        i++;
     }
    }

    void mergeSortedPlaylists(Playlist& other) {
        SortedLinkedList* thisList = dynamic_cast<SortedLinkedList*>(this->list);
        SortedLinkedList* otherList = dynamic_cast<SortedLinkedList*>(this->List);
        if(!thisList || !otherList)
        {
            std::cout << "Invalid. Both lists must be sorted.";
        }
        thisList->Merge(*otherList);
    }
private:
    List* list;
    Node* currentsong;
};

#endif //PLAYLIST_H