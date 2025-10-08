#include "Song.h"

Song::Song(const std:: string& t, const std:: string& a, int d, const std::string& path)
    : title(t), artist(a), duration(d), filePath(path) {}

    bool Song::operator < (const Song& other) const {
        return title < other.title;
    }
    
    bool Song::CompareTo(const ItemType& other) const {
    const Song& otherSong = dynamic_cast<const Song&>(other);
    // Compare for equality
    return (title == otherSong.title &&
            artist == otherSong.artist &&
            duration == otherSong.duration);
}

bool Song::LessThan(const ItemType& other) const {
    const Song& otherSong = dynamic_cast<const Song&>(other);
    // Sort by title alphabetically
    return title < otherSong.title;
}

void Song::Print(std::ostream& out) const {
    out << "Title: " << title << ", Artist: " << artist
        << ", Duration: " << duration << "s"
        << ", Path: " << filePath;
}