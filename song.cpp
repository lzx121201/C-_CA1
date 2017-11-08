#include "song.h"
#include <string>
using namespace std;

Song::Song()
{
  title = "None";
  artist = "None";
  album = "None";
  genre = "None";
  yearReleased = 0;
  lengthInSeconds = 0;
}

Song::Song(string the_title,string the_artist,string the_album,string the_genre,int the_yearReleased,int the_lengthInSeconds)
{
  title = the_title;
  artist = the_artist;
  album = the_album;
  genre = the_genre;
  yearReleased = the_yearReleased;
  lengthInSeconds = the_lengthInSeconds;
}

string Song::formatLength()
{
  int min = lengthInSeconds / 60;
  int sec = lengthInSeconds % 60;
  string str = to_string(min)+"m"+to_string(sec)+"s";
  //string str = "hi";
  return str;
}

string Song::toString()
{
  string str =  "\nTitle: " + title
              + "\nArtist: " + artist
              + "\nAlbum: " + album + "\tGenre: " + genre
              + "\nYear Released: " + to_string(yearReleased) + "\tLength: " + Song::formatLength()
              + " \n-------------------------------------------------";
  return str;
}

string Song::getTitle()
{
  return title;
}

string Song::getArtist()
{
  return artist;
}

string Song::getAlbum()
{
  return album;
}

string Song::getGenre()
{
  return genre;
}

int Song::getYearReleased()
{
  return yearReleased;
}

int Song::getLengthInSeconds()
{
  return lengthInSeconds;
}

void Song::setTitle(string t)
{
  title = t;
}

void Song::setArtist(string a)
{
  artist = a;
}

void Song::setAlbum(string a)
{
  album = a;
}
void Song::setGenre(string g)
{
  genre = g;
}

void Song::setYearReleased(int yr)
{
  yearReleased = yr;
}

void Song::setLengthInSeconds(int min,int sec)
{
  lengthInSeconds = min * 60 + sec ;
}
