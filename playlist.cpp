// Matt Bevis
// Section: 6

//---------------playlist.cpp---------------

#include "playlist.h"
#include <cctype>
#include <cstring>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& os, const Playlist& p)         //ostream operator overload for output of entire playlist
{
    for (int i=0; i < p.currentSize; i++)
        os << p.songList[i] << endl;
    return os;
}

Playlist::Playlist()                                        //default constructor definition
{
    maxSize = 5;
    currentSize = 0;
    songList = new Song[maxSize];
}

Playlist::~Playlist()                                   //destructor defined
{
    delete [] songList;
}

void Playlist::Add(const char* t, const char* a, const char c, const int sz) //function that adds a song to the playlist
{
    Style st;
    switch (c)
    {
    case 'P':
        st = POP;
        break;
    case 'R':
        st = ROCK;
        break;
    case 'A':
        st = ALTERNATIVE;
        break;
    case 'C':
        st = COUNTRY;
        break;
    case 'H':
        st = HIPHOP;
        break;
    case 'Y':
        st = PARODY;
        break;
    }
    Song s;
    s.Set(t, a, st, sz);

    if (maxSize - currentSize < 5)
        maxSize = currentSize + 5;

    Song* newList = new Song[maxSize];

    for (int i = 0; i <= currentSize; i++)
    {
        newList[i] = songList[i];
        if (i == currentSize)
            newList[i] = s;
    }
    currentSize = currentSize + 1;
    delete [] songList;			// Remove the old array
    songList = newList;			// Point old name to new array.
}

void Playlist::Find(char* findSong) const                   //function that finds a song within the playlist
{
    bool isTrue = 0;
    for (int i=0; i <= currentSize; i++)
    {
        if (strcmp(songList[i].GetTitle(), findSong) == 0)
        {
            cout << songList[i];
            isTrue = true;
        }

    }
    if (isTrue == false)
        cout << "Song not found, try again.\n";
    cout << endl;

}

void Playlist::Delete(char* findSong)                       //function that deletes a song from the playlist
{
    bool isTrue = 0;
    for (int i=0; i <= currentSize; i++)
    {
        if (strcmp(songList[i].GetTitle(), findSong) == 0)
        {
            songList[i] = songList[i+1];
            isTrue = true;
        }
    }
    if (isTrue == true)
    {
        currentSize = currentSize - 1;
        Song* newList = new Song[maxSize];
        if (maxSize - currentSize > 5)
            maxSize = currentSize - 1;

        for (int i = 0; i <= currentSize; i++)
        {
            newList[i] = songList[i];
        }
    }
    if (isTrue == false)
        cout << "\nNothing to delete...";

}

void Playlist::ShowPlay(Playlist& p) const                  //function that outputs the whole playlist
{
    if (p.currentSize == 0)
        cout << "There is nothing to display.\n";
    else
    {
        cout << "*Title*" << setw(37) << "*Artist*" << setw(20) << "*Style*" << setw(15) << "*Size (MB)*\n\n";
        cout << p;
    }
}

void Playlist::ShowCat(char& cat, Playlist& p) const        //function that shows songs of a specific category
{
    Style st;
    switch (cat)
    {
    case 'P':
        st = POP;
        break;
    case 'R':
        st = ROCK;
        break;
    case 'A':
        st = ALTERNATIVE;
        break;
    case 'C':
        st = COUNTRY;
        break;
    case 'H':
        st = HIPHOP;
        break;
    case 'Y':
        st = PARODY;
        break;
    }

    for (int i=0; i <= currentSize; i++)
    {
        if (songList[i].GetCategory() == st)
            cout << songList[i] << endl;
    }
}

void Playlist::ShowSize(Playlist& p)                        //function that shows the total size of the playlist in kb
{
    for (int i=0; i <= currentSize; i++)
    {
        totalSize = totalSize + songList[i].GetSize();
    }
    cout << "The total size is " << totalSize << "kb";
}

bool Playlist::IsEmpty(Playlist& p) const                   //function that determines if the playlist is empty and displays a message
{
    if (currentSize == 0)
    {
        cout << "There is nothing to display.\n";
        return true;
    }
    else
        return false;
}
