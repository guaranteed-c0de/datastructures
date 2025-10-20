#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
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
            currentsong = list->GetHead();
        }
    } //Move to next in list.
    void previousSong() {
        if (currentsong == list->GetHead() || currentsong == nullptr) 
        {
            Node* temp = list->GetHead();
            while (temp != nullptr && temp->next != nullptr)
            {
                temp = temp -> next;
            }
             currentsong = temp;
        }
        else {
            //Time to find the previous one..
            Node* temp = list->GetHead();
            while(temp != list->GetHead() && temp ->next != currentsong)
            temp = temp->next;
            currentsong = temp;
        }
    } //Move to previous
    //Add sorting method if extending to sorted list.
    void sortByTitle() {
     Node* currentsong = list->GetHead();
        
     while (currentsong!= nullptr) {
        Song* song = dynamic_cast<Song*>(currentsong->item);
        if(song != nullptr) {
            std::cout << song->title << endl;
        }
        currentsong = currentsong->next;
        
     }
    }

    void mergeSortedPlaylists(Playlist& other) {
        SortedLinkedList* thisList = dynamic_cast<SortedLinkedList*>(this->list);
        SortedLinkedList* otherList = dynamic_cast<SortedLinkedList*>(other.list);
        if(!thisList || !otherList)
        {
            std::cout << "Invalid. Both lists must be sorted.";
        }
        thisList->Merge(*otherList);
    }

    void mergeWithUnsorted(Playlist& unsorted) {
         SortedLinkedList* sortedList = dynamic_cast<SortedLinkedList*>(this->list);
    UnsortedLinkedList* unsortedList = dynamic_cast<UnsortedLinkedList*>(unsorted.list);

    if (!sortedList || !unsortedList) {
        std::cout << "Invalid merge: must merge a sorted playlist with an unsorted one.\n";
        return;
    }

    unsortedList->SortThis(*sortedList);
    std::cout << "Merged unsorted playlist into sorted playlist successfully.\n";
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
    Node* currentsong;
};

#endif //PLAYLIST_H