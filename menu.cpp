// Matt Bevis
// Section: 6

//---------------menu.cpp---------------

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "playlist.h"

using namespace std;



void ShowMenu()         //void function for menu display
{
    cout << "A:   Add a song to the playlist\n"
         << "F:   Find a song on the playlist\n"
         << "D:   Delete a song from the playlist\n"
         << "S:   Show the entire playlist\n"
         << "C:   Category summary\n"
         << "Z:   Show the playlist size\n"
         << "M:   Show this Menu\n"
         << "X:   Exit the program\n\n";
}
int main()
{
    char findSong[36];                  //variables and arrays to pass to input to functions
    char findCat;
    char selection;
    char addTitle[36];
    char addArtist[21];
    char addCat;
    int addSize;
    ShowMenu();
    Playlist p;                         // declaration of default constructor
    do                                  //do-while loop to keep the user in the program as long as they'd like
    {
        cout << "> ";

        cin  >> selection;
        selection = toupper(selection);
        switch (selection)              //switch statement to transfer the user to different options
        {
        case 'A':                       //case a to add a song
            cout << "\tADD A SONG:\n---------------------------\n";
            cout << "Title: ";
            cin.ignore();
            cin.getline(addTitle, 35);
            cout << endl;

            cout << "Artist: ";
            cin.getline(addArtist, 20);
            cout << "\n\n";

            cout << "P - Pop\n"
                 << "R - Rock\n"
                 << "A - Alternative\n"
                 << "C - Country\n"
                 << "H - HipHop\n"
                 << "Y - Parody\n\n";
            cout << "Category: ";
            cin  >> addCat;
            addCat = toupper(addCat);
            while(addCat != 'P' && addCat != 'R' && addCat != 'A'
               && addCat != 'C' && addCat != 'H' && addCat != 'Y')
            {
                cout << "\nPlease enter a valid category: ";
                cin  >> addCat;
                addCat = toupper(addCat);
                cout << endl;
            }

            cout << "Size: ";
            cin  >> addSize;
            while (addSize <= 0)
            {
                cout << "\nMust enter a positive size. Please re-enter: ";
                cin  >> addSize;
                cout << endl;
            }
            cout << endl;
            p.Add(addTitle, addArtist, addCat, addSize);
            break;
        case 'F':                   // case f to find a song
            if (p.IsEmpty(p) == true)
                break;
            else
            {
                cout << "Title: ";
                cin.ignore();
                cin.getline(findSong, 35);
                p.Find(findSong);
                break;
            }
        case 'D':                   // case d to delete a song
            if (p.IsEmpty(p) == true)
                break;
            else
            {
                cout << "Title: ";
                cin.ignore();
                cin.getline(findSong, 35);
                p.Delete(findSong);
                break;
            }
        case 'S':                   // case s to show the entire playlist
            p.ShowPlay(p);
            break;
        case 'C':                   // case c to show only songs of a specific category
            if (p.IsEmpty(p) == true)
                break;
            else
            {
            cout << "P - Pop\n"
                 << "R - Rock\n"
                 << "A - Alternative\n"
                 << "C - Country\n"
                 << "H - HipHop\n"
                 << "Y - Parody\n\n";
            cout << "Category: ";
                cin  >> findCat;
                findCat = toupper(findCat);
                p.ShowCat(findCat, p);
                break;
            }

        case 'Z':               // case z to show the total file size of the playlist
            p.ShowSize(p);
            cout << endl;
            break;
        case 'M':               // case m to reshow the menu
            ShowMenu();
            break;
        case 'X':               // case x to eXit the program
            p.~Playlist();
            break;
        default:                // default in the event that the user makes an invalid selection
            cout << "Please make a valid selection: \n";
            break;
        }
    }while(selection != 'X');
    cout << "~Goodbye!~";      //exit program
    return 0;
}
