// 8 million songs, different type, organized with last play date, name, type
// Pick 350 songs recently played, 30% rap, 30% country, 40% jazz

#include <vector>
#include <string>
#include <algorithm>    //Sort

using namespace std;

class Song {

public: 
    string song_name, type;
    Date last_play_date;

};

struct Date {
    unsigned int day, month, year;
};

//compare dates
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

int PickSongs(Song* songs[8M]) {

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

