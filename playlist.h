// Matt Bevis
// Section: 6

//---------------playlist.h---------------

#include "song.h"
#include <iostream>

class Playlist
{

friend ostream& operator<<(ostream& os, const Playlist& p); //ostream operator overload

public:
Playlist();                                                         //class function definitions
~Playlist();
void Add(const char* t, const char* a, const char c, const int sz);
void Find(char* fs) const;
void Delete(char* fs);
void ShowPlay(Playlist& p) const;
void ShowCat(char& cat, Playlist& p) const;
void ShowSize(Playlist& p);
bool IsEmpty(Playlist& p) const;

private:                                                            //private member data
Song s;
int	maxSize,		    // the maximum allowable number of entries
    currentSize;		// the current number of entries
Song* songList;		// pointer to the list of entries
void Grow();			// Increase maximum size, when required.
char selection;
int totalSize;
};
