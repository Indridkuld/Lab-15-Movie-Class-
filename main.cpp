// COMSC-210 | Lab 15: Movie Class | Aidan Woodcock | 2025-09-28
// IDE used: Visual Studio Code

#include <iostream>
#include <array>
#include <fstream>

using namespace std; 
// Movie class definition with private members and public methods
class Movie {
    private: 
    string screenWriter;
    int yearReleased;
    string title;

    public:
    void swSetter(string sw) {screenWriter = sw;}
    void yrSetter(int yr) {yearReleased = yr;}
    void titleSetter(string t) {title = t;}
    // getters with const correctness
    string swGetter() const {return screenWriter;}
    int yrGetter() const {return yearReleased;}
    string titleGetter() const {return title;}
    // display method with const correctness
    void display() const {
        cout << "Movie: " << title << endl;
        cout << "Year Released: " << yearReleased << endl;
        cout << "Screenwriter: " << screenWriter << endl;
    }
};

int main() {
    array<Movie, 4> tempMovies; // Array to hold 4 Movie objects
    ifstream fin; 
    fin.open("input.txt");
    if (!fin.good()) { // Check if file opened successfully
        cerr << "Error opening file." << endl;
        return 1;
    }
    // for loop to read movie data from file and set object attributes
    for (int i = 0; i < tempMovies.size(); ++i) {
        string temptitle, tempscreenWriter;
        int tempyear;

        getline(fin, temptitle);
        fin >> tempyear;
        fin.ignore(); 
        getline(fin, tempscreenWriter);
        tempMovies[i].titleSetter(temptitle);
        tempMovies[i].yrSetter(tempyear);
        tempMovies[i].swSetter(tempscreenWriter);
    }
    // for loop to display movie information using display method in Movie class
    for (int i = 0; i < tempMovies.size(); ++i) {
        tempMovies[i].display();
        cout << endl;
    }

    return 0;
}