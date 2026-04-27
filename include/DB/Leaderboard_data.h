#pragma once
#include "Data_base.h"

// will store after gameover and sort them
class Leaderboard
{

private:
    Data_base db;

    int rank[10];
    string username[10];
    int score[10];
    int levelReached[10];
    string date[10];

    // private so can only be used by the methods of this class
    void sort();

public:
    Leaderboard();
    ~Leaderboard();

    void getTopTen();
    void insertScore(const string& uname, int s, int level, const string& d);

    // getters
    int getRank(int i) const;
    string getUsername(int i) const;
    int getScore(int i) const;
    int getLevelReached(int i) const;
    string getDate(int i) const;

};



// helper functions
void swap(string & a, string & b);
void swap(int & a, int & b);
