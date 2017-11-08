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
    cout << "\t3. Remove A Song From Library." << endl;
    cout << "\t4. Edit A Song's Properties." << endl;
    cout << "\t5. Search Songs." << endl;
    cout << "\t6. Sort Songs." << endl;



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
    else if(option == "3")
    {

    }
    else if(option == "4")
    {
      editItems();
    }
    else if(option == "5")
    {

    }
    else if(option == "6")
    {

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

void Library::editItems()
{
  int toBeEdited = 0;
  string sub_option_1 = "1";
  while (sub_option_1 != "-1")
  {
    cout << songs[toBeEdited].toString() << endl;
    cout << "1. Edit title" << endl;
    cout << "2. Edit artist" << endl;
    cout << "3. Edit album" << endl;
    cout << "4. Edit genre" << endl;
    cout << "5. Edit year released" << endl;
    cout << "6. Edit song length" << endl;
    cout << "-1. Return to menu" << endl;
    cout << "Option: ";
    cin >> sub_option_1;
    cin.ignore();

    if(sub_option_1 == "1")
    {
      string t;
      cout << "Enter the title: ";
      getline(cin,t);
      songs[toBeEdited].setTitle(t);
      saveChanges();

    }
    else if(sub_option_1 == "2")
    {
      string a;
      cout << "Enter the artist: ";
      getline(cin,a);
      songs[toBeEdited].setArtist(a);
      saveChanges();

    }
    else if(sub_option_1 == "3")
    {
      string a;
      cout << "Enter the album: ";
      getline(cin,a);
      songs[toBeEdited].setAlbum(a);
      saveChanges();

    }
    else if(sub_option_1 == "4")
    {
      string g;
      cout << "Enter the genre: ";
      getline(cin,g);
      songs[toBeEdited].setGenre(g);
      saveChanges();

    }
    else if(sub_option_1 == "5")
    {
      int yr;
      cout << "Enter the year released: ";
      cin >> yr;
      songs[toBeEdited].setYearReleased(yr);
      saveChanges();

    }
    else if(sub_option_1 == "6")
    {
      int mins,secs;
      cout << "\nEnter the minutes: ";
      cin >> mins;
      cout << "\nEnter the seconds: ";
      cin >> secs;
      songs[toBeEdited].setLengthInSeconds(mins,secs);
      saveChanges();

    }
    else if(sub_option_1 == "-1")
    {
      break;
    }
    else
    {
      cout << "Invalid input, please enter again." << endl;
    }

  }
}

void Library::sortItems()
{
  string sub_option_2 = "1";
  while (sub_option_2 != "-1")
  {
    cout << "1. Sort by title" << endl;
    cout << "2. Sort by artist" << endl;
    cout << "3. Sort by album" << endl;
    cout << "4. Sort by genre" << endl;
    cout << "5. Sort by year released" << endl;
    cout << "6. Sort by song length" << endl;
    cout << "-1. Return to menu" << endl;
    cout << "Option: ";
    cin >> sub_option_2;
    cin.ignore();

    if(sub_option_2 == "1")
    {

    }
    else if(sub_option_2 == "2")
    {

    }
    else if(sub_option_2 == "3")
    {


    }
    else if(sub_option_2 == "4")
    {

    }
    else if(sub_option_2 == "5")
    {

    }
    else if(sub_option_2 == "6")
    {

    }
    else if(sub_option_2 == "-1")
    {
      break;
    }
    else
    {
      cout << "Invalid input, please enter again." << endl;
    }
  }
}
