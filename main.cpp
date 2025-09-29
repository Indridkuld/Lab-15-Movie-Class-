// COMSC-210 | Lab 15: Movie Class | Aidan Woodcock | 2025-09-28
// IDE used: Visual Studio Code

#include <iostream>
#include <array>
#include <fstream>

using namespace std; 

class Movie {
    private: 
    string screenWriter;
    int yearReleased;
    string title;

    public:
    void swSetter(string sw) {screenWriter = sw;}
    void yrSetter(int yr) {yearReleased = yr;}
    void titleSetter(string t) {title = t;}
    string swGetter() const {return screenWriter;}
    int yrGetter() const {return yearReleased;}
    string titleGetter() const {return title;}

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Screenwriter: " << screenWriter << endl;
        cout << "Year Released: " << yearReleased << endl;
    }
};

int main() {
    array<Movie, 4> tempMovies;
    ifstream fin; 
    fin.open("input.txt");
    if (!fin.good()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    for (int i = 0; i < tempMovies.size(); ++i) {
        string title, screenWriter;
        getline(fin, title);
        tempMovies[i].titleSetter(title);
        getline(fin, screenWriter);
        tempMovies[i].swSetter(screenWriter);
        int year;
        fin >> year;
        fin.ignore(); // To ignore the newline character after the integer input
        tempMovies[i].yrSetter(year);
    }
    for (int i = 0; i < tempMovies.size(); ++i) {
        tempMovies[i].display();
        cout << endl;
    }

    return 0;
}