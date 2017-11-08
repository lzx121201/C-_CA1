#pragma once
#include <string>
using namespace std;
class Song
{
  protected:
    string title;
    string artist;
    string album;
    string genre;
    int yearReleased;
    int lengthInSeconds;

  public:
    Song();
    Song(string the_title,string the_artist,string the_album,string the_genre,int the_yearReleased,int the_lengthInSeconds);
    string formatLength();
    string toString();
    string getTitle();
    string getArtist();
    string getAlbum();
    string getGenre();
    int getYearReleased();
    int getLengthInSeconds();
    void setTitle(string t);
    void setArtist(string a);
    void setAlbum(string a);
    void setGenre(string g);
    void setYearReleased(int yr);
    void setLengthInSeconds(int min,int sec);


};
