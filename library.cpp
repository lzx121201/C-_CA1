#include "library.h"
#include "song.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Library::displayAll(vector<Song> results)
{
  for(Song s : results)
  {
    cout<<s.toString()<<endl;
  }
}

void Library::saveChanges()
{
  string fileName = "test2.txt";
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

void Library::loadData()
{
  string fileName = "test2.txt";
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
    cout << "\t7. Export to HTML Table." << endl;

    cout << "Option: ";
    cin >> option;
    cout << "-------------------------------------------------\n" << endl;
    cin.ignore();
    if(option == "1")
    {
      displayAll(songs);
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
      int id;
      cout << "Enter song ID: ";
      cin >> id;
      deleteItems(id);
    }
    else if(option == "4")
    {
      int id;
      cout << "Enter song ID: ";
      cin >> id;
      editItems(id);
    }
    else if(option == "5")
    {
      searchItems();
    }
    else if(option == "6")
    {
      sortItems();
    }
    else if (option == "7")
    {
      exportToHTMLTable();
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

void Library::editItems(int id)
{
  if( searchByID(id).size() == 0)
  {
    cout << "\nNo such song found.\n-------------------------------------------------" << endl;

  }
  else
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
}

bool sortByTitle(Song s1, Song s2)
{
  return s1.getTitle() < s2.getTitle();
}

bool sortByArtist(Song s1, Song s2)
{
  return s1.getArtist() < s2.getArtist();
}

bool sortByAlbum(Song s1, Song s2)
{
  return s1.getAlbum() < s2.getAlbum();
}

bool sortByGenre(Song s1, Song s2)
{
  return s1.getGenre() < s2.getGenre();
}

bool sortByYearReleased(Song s1, Song s2)
{
  return s1.getYearReleased() < s2.getYearReleased();
}

bool sortByLengthInSeconds(Song s1, Song s2)
{
  return s1.getLengthInSeconds() < s2.getLengthInSeconds();
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
      sort(songs.begin(),songs.end(),sortByTitle);
      displayAll(songs);
    }
    else if(sub_option_2 == "2")
    {
      sort(songs.begin(),songs.end(),sortByArtist);
      displayAll(songs);
    }
    else if(sub_option_2 == "3")
    {
      sort(songs.begin(),songs.end(),sortByAlbum);
      displayAll(songs);
    }
    else if(sub_option_2 == "4")
    {
      sort(songs.begin(),songs.end(),sortByGenre);
      displayAll(songs);
    }
    else if(sub_option_2 == "5")
    {
      sort(songs.begin(),songs.end(),sortByYearReleased);
      displayAll(songs);
    }
    else if(sub_option_2 == "6")
    {
      sort(songs.begin(),songs.end(),sortByLengthInSeconds);
      displayAll(songs);
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

vector<Song> Library::searchByID(int id)
{
  bool found = false;
  int i = 0;
  vector<Song> results;
  while(i < songs.size() && found == false )
  {
    if( songs[i].getSongID() == id)
    {
      results.push_back(songs[i]);
      found = true;
    }
    i++;
  }
  return results;
}

vector<Song> Library::searchByTitle(string title)
{
  bool found = false;
  int i = 0;
  vector<Song> results;
  while(i < songs.size() && found == false )
  {
    if( songs[i].getTitle() == title)
    {
      results.push_back(songs[i]);
      found = true;
    }
    i++;
  }
  return results;
}

vector<Song> Library::searchByAlbum(string album)
{
  bool found = false;
  int i = 0;
  vector<Song> results;
  while(i < songs.size() && found == false )
  {
    if( songs[i].getAlbum() == album)
    {
      results.push_back(songs[i]);
      found = true;
    }
    i++;
  }
  return results;
}

vector<Song> Library::searchByArtist(string artist)
{
  bool found = false;
  int i = 0;
  vector<Song> results;
  while(i < songs.size() && found == false )
  {
    if( songs[i].getArtist() == artist)
    {
      results.push_back(songs[i]);
      found = true;
    }
    i++;
  }
  return results;
}

void Library::searchItems()
{
  string sub_option_3 = "1";
  while (sub_option_3 != "-1")
  {
    cout << "1. Search by ID" << endl;
    cout << "2. Search by title" << endl;
    cout << "3. Search by album" << endl;
    cout << "4. Search by artist" << endl;
    cout << "-1. Return to menu" << endl;
    cout << "Option: ";
    cin >> sub_option_3;
    cin.ignore();

    if(sub_option_3 == "1")
    {
      int id;
      cout << "Enter song ID: ";
      cin >> id;
      vector<Song> results = searchByID(id);
      if( results.size() == 0)
      {
        cout << "\nNo songs found.\n-------------------------------------------------" << endl;
      }
      else
      {
        displayAll(results);
      }
    }
    else if(sub_option_3 == "2")
    {
      string title;
      cout << "Enter title: ";
      getline(cin, title);
      vector<Song> results = searchByTitle(title);
      if( results.size() == 0)
      {
        cout << "\nNo songs found.\n-------------------------------------------------" << endl;
      }
      else
      {
        displayAll(results);
      }
    }
    else if(sub_option_3 == "3")
    {
      string album;
      cout << "Enter album: ";
      getline(cin, album);
      vector<Song> results = searchByTitle(album);
      if( results.size() == 0)
      {
        cout << "\nNo songs found.\n-------------------------------------------------" << endl;
      }
      else
      {
        displayAll(results);
      }
    }
    else if(sub_option_3 == "4")
    {
      string artist;
      cout << "Enter artist: ";
      getline(cin, artist);
      vector<Song> results = searchByTitle(artist);
      if( results.size() == 0)
      {
        cout << "\nNo songs found.\n-------------------------------------------------" << endl;
      }
      else
      {
        displayAll(results);
      }
    }
    else if(sub_option_3 == "-1")
    {
      break;
    }
    else
    {
      cout << "Invalid input, please enter again." << endl;
    }
  }
}

void Library::deleteItems(int id)
{
  if( searchByID(id).size() == 0)
  {
    cout << "\nNo such song found.\n-------------------------------------------------" << endl;

  }
  else
  {
    int toBeDeleted = id;
    vector<Song>::size_type i;
    while(i != songs.size())
    {
    	if(songs[i].getSongID() == toBeDeleted)
    	{
    		songs.erase(songs.begin()+i);
    	}
    	else
    	{
    		i++;
    	}
    }

    if(searchByID(toBeDeleted).size() == 0)
    {
      cout << "Deleted successfully.\n-------------------------------------------------" << endl;
      saveChanges();
    }
    else
    {
      cout << "Fail to delete.\n-------------------------------------------------" << endl;

    }
  }
}


void Library::exportToHTMLTable()
{
  string fileName = "library.html";
  ofstream file;
  //file.exceptions( ifstream::failbit | ifstream::badbit );
  try {
    file.open(fileName);

    file << "<html> <head> <title>Song Library</title>  <style> table, th, td { border: 2px solid black;border-collapse: collapse; text-align:center; } </style> </head> <body> " << endl;
    file << "<table> <tr> <th>Title</th> <th>Artist</th> <th>Album</th> <th>Genre</th> <th>Yeat Released</th> <th>Length</th> </tr>" << endl;

    for(Song s : songs)
    {
      file << s.toHTMLTable() << endl;
    }

    file << "</table> </body> </html>" << endl;

    file.close();

    cout << "Export Done!\n-------------------------------------------------" << endl;
  }
  catch ( const ofstream::failure& e ) {
    cout << "exception occurred!" << endl;
  }
}
