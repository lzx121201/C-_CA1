#include "library.h"
#include "song.h"
#include <string>
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

Library::Library()
{
  string fileName = "test1.txt";
  ifstream file;
  //file.exceptions( ifstream::failbit | ifstream::badbit );

  try {
    file.open(fileName);
    while (!file.eof()) {
      string title;
      string artist;
      string album;
      string genre;
      string year;
      string length;

      getline(file,title);
      getline(file,artist);
      getline(file,album);
      getline(file,genre);
      getline(file,year);
      getline(file,length);
      int yearReleased = stoi(year);
      int lengthInSeconds = stoi(length);
      Song song(title,artist,album,genre,yearReleased,lengthInSeconds);
      songs.push_back(song);
    }
    file.close();
  }
  catch ( const ifstream::failure& e ) {
    cout << "exception occurred!" << endl;
  }
}

void Library::displayAll()
{
  for(Song s : songs)
  {
    cout<<s.toString()<<endl;
  }
}
