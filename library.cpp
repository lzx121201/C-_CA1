#include "library.h"
#include "song.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Library::displayAll()
{
  for(Song s : songs)
  {
    cout<<s.toString()<<endl;
  }
}

void Library::saveChanges()
{
  string fileName = "test1.txt";
  ofstream file;
  //file.exceptions( ifstream::failbit | ifstream::badbit );
  try {
    file.open(fileName);
    for(int i = 0; i < songs.size(); i++)
    {
      file << songs[i].getTitle() << endl;
      file << songs[i].getArtist() << endl;
      file << songs[i].getAlbum() << endl;
      file << songs[i].getGenre() << endl;
      file << songs[i].getYearReleased() << endl;
      if( i== songs.size() - 1)
      {
        file << songs[i].getLengthInSeconds();
      }
      else
      {
        file << songs[i].getLengthInSeconds() << endl;
      }
    }
    file.close();
  }
  catch ( const ofstream::failure& e ) {
    cout << "exception occurred!" << endl;
  }
}

void Library::addItems()
{
  string title;
  string artist;
  string album;
  string genre;
  int year;
  int mins;
  int secs;
  cout << "Enter the title: ";
  getline(cin,title);
//  cin >> title >> endl;

  cout << "\nEnter the artist: ";
  getline(cin,artist);
//  cin >> artist >> endl;

  cout << "\nEnter the album: ";
//  cin >> album >> endl;
  getline(cin,album);

  cout << "\nEnter the genre: ";
//  cin >> genre >> endl;
  getline(cin,genre);

  cout << "\nEnter the year released: ";
  cin >> year;
  //getline(cin,yearReleased);

  cout << "\nEnter the minutes: ";
  cin >> mins;

  cout << "\nEnter the seconds: ";
  cin >> secs;
  int lenght = 60 * mins +secs;

  Song song(title,artist,album,genre,year,lenght);

  songs.push_back(song);

  saveChanges();
}

void Library::loadData()
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

void Library::runAPP()
{
  loadData();
  string option = "0" ;
  while(option != "-1")
  {
    cout << "Welcome, please enter your choice (Enter '-1' to exit):" << endl;
    cout << "\t1. Display All Songs." << endl;
    cout << "\t2. Add A New Song." << endl;

    cout << "Option: ";
    cin >> option;
    cin.ignore();
    if(option == "1")
    {
      displayAll();
    }
    else if( option == "2")
    {
      string sub_option = "1";
      while(sub_option != "-1")
      {
        if( sub_option == "1")
        {
          addItems();
          cout << "Do wish to continue to add a new song?" << endl;
          cout << "\t Continue('1') or Return to Menu('-1')" << endl;
          cout << "Option: ";
          cin >> sub_option;
        }
        else
        {
          break;
        }
      }
    }
    else if(option == "-1")
    {
      cout << "Bye!" <<endl;
      break;
    }
    else
    {
      cout << "Invalid input, please enter again." << endl;
    }
  }
}
