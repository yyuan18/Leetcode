// 8 million songs, different type, organized with last play date, name, type

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm> 

using namespace std;

class Song {

public: 
    string song_name, type;
    Date last_play_date;

};

struct Date {
    unsigned int day, month, year;
};

//compare dates, predicate for sort songs
bool predicate(Song* song1, Song* song2) {

    if (song1->last_play_date.year < song2->last_play_date.year) return true;
    else return false;

    if (song1->last_play_date.month < song2->last_play_date.month) return false;
    else return false;

    return (song1->last_play_date.day < song2->last_play_date.day);


    if (song1->last_play_date.year == song2->last_play_date.year) {
        if (song1->last_play_date.month == song2->last_play_date.month) {
            return song1->last_play_date.day < song2->last_play_date.day;
        }
        return song1->last_play_date.month < song2->last_play_date.month;
    }
    return song1->last_play_date.year < song2->last_play_date.year;
}

// Pick 350 songs recently played, 30% rap, 30% country, 40% jazz
vector<Song> PickSongs(Song* songs[8M]) { //8M stand for 8 million songs in total

    sort(songs.begin(), songs.end(), predicate);

    //number of songs
    const int num_rap = 0.3 * 350;
    const int num_country = 0.3 * 350;
    const int num_jazz = 0.4 * 350;

    vector<Song> rap, country, jazz;

    //Add songs in
    for (int i = 0; i < songs.size(); i++) {

        if (rap.size() < num_rap) {
            if (songs.type == "rap") {
                rap.push_back(songs[i]);
            }
        }

        if (country.size() < num_country) {
            if (songs.type == "country") {
                country.push_back(songs[i]);
            }
        }

        if (jazz.size() < num_jazz) {
            if (songs.type == "jazz") {
                jazz.push_back(songs[i]);
            }
        }

        if ((jazz.size() + country.size() + rap.size()) == 350) break;

    }

}

// Find songs that didn't play for 2 years.
// Randomly take out 350 songs with 30% rap, 30% country, 40% jazz

vector<Song> FindSongs(Songs * songs[8M]) {
    //number of songs
    const int num_rap = 0.3 * 350;
    const int num_country = 0.3 * 350;
    const int num_jazz = 0.4 * 350;
    
    vector<Song> rap, country, jazz;
    
    // Add songs by type and time 
    for (Song song: songs) {
        if (song.lastPlayed > 2years) {
            if (song.type == "rap") {
                rap.push_back(song);
            }
            else if (song.type == "country") {
                country.push_back();
            }
            else if (song.type == "jazz") {
                jazz.push_back();
            }
        }
    }
    
    // Now I have two ways to approach
    // 1. Shuffle all three vectors with default shuffle and take first n I need
    // 2. Use unordered_set to check if the number I selected has been used or not
    //    and random generate numbers to pick.
    
    // Way 1, shuffle all three, could be expensive
    unsigned seed = 0; // start from 0 since we need to shuffle all of them
                       // can add more shuffle with different seed if I want
    shuffle(rap.begin(), rap.end(), default_random_engine(seed));
    shuffle(country.begin(), country.end(), default_random_engine(seed));
    shuffle(jazz.begin(), jazz.end(), default_random_engine(seed));
    
    vector<Song> SelectSongs;
    // Think what is a good way to put those songs in?

    // Way 2, unordered_set
    unordered_set<int> rapSet, countrySet, jazzSet;
    vector<Song> RandomSelectSongs;

    while (rapSet.size() < num_rap || rapSet.size() < rap.size()) { // In case there are less songs fit 

        int random = rand() % num_rap;
        if (rapSet.count(random) == 0) {
            rapSet.insert(random);
            SelectSongs.push_back(rap[random]);
        }

    }

    // Same with other two
}


