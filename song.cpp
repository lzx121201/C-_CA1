#include "song.h"
#include <string>
using namespace std;

int Song::song_id = 0;

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
  song_id ++ ;
  id = song_id;
  title = the_title;
  artist = the_artist;
  album = the_album;
  genre = the_genre;
  yearReleased = the_yearReleased;
  lengthInSeconds = the_lengthInSeconds;
}

Song::~Song()
{

}

string Song::formatLength()
{
  int min = lengthInSeconds / 60;
  int sec = lengthInSeconds % 60;
  string str = to_string(min) + "m" + to_string(sec) + "s";
  //string str = "hi";
  return str;
}

string Song::toString()
{
  string str = "\nTitle: " + title
              + "\nSong ID: " + to_string(id) + "\tArtist: " + artist
              + "\nAlbum: " + album + "\tGenre: " + genre
              + "\nYear Released: " + to_string(yearReleased) + "\tLength: " + formatLength()
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

int Song::getSongID()
{
  return id;
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

string Song::toHTMLTable()
{
  string str = "<tr> <td>" + title + "</td>"
              + "<td>" + artist + "</td>"
              + "<td>" + album + "</td>"
              + "<td>" + genre + "</td>"
              + "<td>" + to_string(yearReleased) + "</td>"
              + "<td>" + formatLength() + "</td>"
              + "</tr>";
  return str;
}

string Song::toJsonFormat()
{
  string str = "\"Song\":{\"Title\": \"" + title + "\","
                + "\"Artist\": \"" + artist + "\","
                + "\"Album\": \"" + album + "\","
                + "\"Genre\": \"" + genre + "\","
                + "\"yearReleased\": \"" + to_string(yearReleased) + "\","
                + "\"length\": \"" + formatLength() + "\"}";
  return str;
}

string Song::toXmlFormat()
{
  string str = "<Song> <title>" + title + "</title>"
              + "<artist>" + artist + "</artist>"
              + "<album>" + album + "</album>"
              + "<genre>" + genre + "</genre>"
              + "<yearReleased>" + to_string(yearReleased) + "</yearReleased>"
              + "<length>" + formatLength() + "</length>";
  return str;
}

string Song::toSQLInsertQuery()
{
  string str = "INSERT INTO songs (title, artist, album, genre, year_released, length_seconds) VALUES(\"" + title + "\","
              + "\"" + artist + "\","
              + "\"" + album + "\","
              + "\"" + genre + "\","
              +  to_string(yearReleased) + ","
              +  to_string(lengthInSeconds) + ");";
  return str;
}
