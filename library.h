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
    void displayAll();
    void saveChanges();
    void addItems();
    void loadData();
    void runAPP();
};
