// COMSC-210 | Lab 15: Movie Class | Aidan Woodcock | 2025-09-28
// IDE used: Visual Studio Code

#include <iostream>

using namespace std; 

class Movie {
    private: 
    string screenWriter;
    int yearReleased;
    string title;

    public:
    void swSetter(string sw) {screenWriter = sw;}

};