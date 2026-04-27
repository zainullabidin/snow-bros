// Minahil

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// data files created 
const string USERS_FILE       = "data/users.txt";
const string PROGRESS_FILE    = "data/progress.txt";
const string LEADERBOARD_FILE = "data/leaderboard.txt";

class Data_base
{
private:
    string *lines;
    int count;          // no of lines in file
    int capacity;       // no of lines a file can hold

    

public:
    Data_base(int cap);
    ~Data_base();

    string getLine (int index) const;
    // getetrs
    int getCount () const;
    int getCapacity() const;
    void setCount(int Count);
    void setCapacity(int Capacity);
    void setLine(int index, const string& line);
    
    // methods
    void readAllLines(const string& filename);
    void writeAllLines(const string& filename);
    void appendLine(const string& filename, const string& line);
    bool fileExists(const string& filename);
    void createFileIfMissing(const string& filename);
    void clear();

    void resize(); // doubles capacity, reallocates lines array
};


// a free split string funtion that is to be used by all other classes 
// + authority manager also
// making it public in this class would have become complicated
void splitstring(string str, char delimeter, string parts[], int &partCount);
