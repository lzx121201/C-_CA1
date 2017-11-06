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
    Library();
    string toString(Song aSong);
    void displayAll();
};
