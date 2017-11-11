#pragma once
#include <string>
#include <vector>
#include "song.h"
using namespace std;

class Library
{
  private:
    vector<Song> songs;

  public:
    void displayAll(vector<Song> results);
    void saveChanges();
    void addItems();
    void loadData();
    void runAPP();
    void editItems(int id);
    void sortItems();
    vector<Song> searchByID(int id);
    vector<Song> searchByTitle(string title);
    vector<Song> searchByAlbum(string album);
    vector<Song> searchByArtist(string artist);
    void searchItems();
    void deleteItems(int id);
    void exportToHTMLTable(string str);
    void exportToJsonFile(string str);
    void exportToXmlFile(string str);
    void exportItems();



};
