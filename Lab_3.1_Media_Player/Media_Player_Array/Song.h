#ifndef SONG_H
#define SONG_H
#include "ItemType.h"
#include <string>

class Song : public ItemType {
    public: 
    std:: string title;
    std:: string artist;
    int duration; //In seconds
    std:: string filePath; //path to MP3 file
    bool CompareTo(const ItemType& other) const override;
    bool LessThan(const ItemType& other) const override;
    void Print(std::ostream& out) const override;

    Song(const std:: string& t, const std:: string& a, int d, const std::string& path);
        bool operator < (const Song& other) const;
};
#endif //SONG_H