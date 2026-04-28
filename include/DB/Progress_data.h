#pragma once
#include "User_data.h"

class Progress_data {
private:

    // db object
    Data_base db;

    // basic requirements
    int userId;
    int currentLevel;
    int livesRemaining;
    int gemCount;
    int highScore;
    string lastUpdated;

public:

    Progress_data();
    ~Progress_data();

    bool loadProgress(int uid);   // fills members, returns false if not found
    void saveProgress(int uid, int level, int lives, int gems, int score);
    void updateGems(int uid, int gemCount);
    void updateHighScore(int uid, int score);

    // getters
    int getCurrentLevel();
    int getLivesRemaining() ;
    int getGemCount() ;
    int getHighScore() ;
    string getLastUpdated() ;

};

// a function that gets the date in yyyy - mm-dd format for current time
string getTodaysDate();
