// Matt Bevis
// Section: 6

//---------------song.cpp---------------

#include "song.h"
#include <iomanip>
#include <cstring>

using namespace std;

ostream& operator<<(ostream& os, const Song& s)     //ostream operator overload to display a song in a formatted way
{
    double sizeChange;
    int i = 0;
    int tLength = strlen(s.title);
    while (i <= tLength)
    {
        os << s.title[i];
        i++;
    }
    tLength = 35 - tLength;
    for (int i=0; i <= tLength; i++)
        os << " ";
    i = 0;
    int aLength = strlen(s.artist);
    while (i <= aLength)
    {
        os << s.artist[i];
        i++;
    }
    aLength = 20 - aLength;
    for (int i=0; i <= aLength; i++)
        os << " ";
    if (s.category == POP)
        os << "Pop";
    else if (s.category == ROCK)
        os << "Rock";
    else if (s.category == ALTERNATIVE)
        os << "Alt";
    else if (s.category == COUNTRY)
        os << "Ctry";
    else if (s.category == HIPHOP)
        os << "HH";
    else if (s.category == PARODY)
        os << "Prdy";
    os << "\t\t";
    sizeChange = s.size / 1000.0;
    os << fixed << setprecision(1);
    os << sizeChange;
    return os;
}

Song::Song()                            // default constructor of the song class
{
    strcpy(title, " ");
    strcpy(artist, " ");
    category;
    size = 0;
}

void Song::Set(const char* t, const char* a, Style st, int sz) //function that sets a song with the correct information
{
    int tLength = strlen(t);
    int aLength = strlen(a);
    for (int i=0; i <= tLength; i++)
        title[i] = t[i];
    for (int i=0; i <= aLength; i++)
        artist[i] = a[i];
    category = st;
    size = sz;
}

const char* Song::GetTitle() const              //returns the title of the song
{
    return title;
}

const char* Song::GetArtist() const             //returns the artist of the song
{
    return artist;
}

int Song::GetSize() const                       //returns the size of the song
{
    return size;
}

Style Song::GetCategory() const                 //returns the category of the song
{
    return category;
}


