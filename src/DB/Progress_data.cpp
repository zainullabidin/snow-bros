#include"../../include/DB/Progress_data.h"
#include <ctime>
#include <string>

// constructor 
Progress_data::Progress_data() : db(10) 
{
    db.createFileIfMissing(PROGRESS_FILE);
    
    userId = 0; 
    currentLevel = 1;
    livesRemaining = 2; 
    gemCount = 0;
    highScore = 0;
    lastUpdated = ""; 
}

Progress_data::~Progress_data() {
    db.clear();
}

// simply a free function to get time
// yyyy - mm -- dd
string getTodaysDate() {
    // get time in secs after 1900
    time_t t = time(0);

    // convert to readable format  and get local time
    tm* now = localtime(&t);

    string year = to_string(now->tm_year + 1900);  // tm_year after `1900`
    string month = (now->tm_mon + 1 < 10 ? "0" : "") + to_string(now->tm_mon + 1);  // tm_mon   0 -11 months,
    string day = (now->tm_mday < 10 ? "0" : "") + to_string(now->tm_mday);

    return year + "-" + month + "-" + day ;
}


// fills members, returns false if not found
bool Progress_data::loadProgress(int uid) {
    // load progress from database
    db.readAllLines(PROGRESS_FILE);

    string parts[6];
    int partCount = 0;

    for(int i = 0; i < db.getCount(); i++)
    {
        splitstring(db.getLine(i), '|', parts, partCount);

        if(partCount >= 6 && stoi(parts[0]) == uid)
        {
            userId = uid;
            currentLevel = stoi(parts[1]);
            livesRemaining = stoi(parts[2]);
            gemCount = stoi(parts[3]);
            highScore = stoi(parts[4]);
            lastUpdated = parts[5];
            return true;
        }
    }

    // if not found, set safe defaults , so that garabge val is not stored, and give unreasonable outputs
    userId = uid; 
    currentLevel = 1;
    livesRemaining = 2; 
    gemCount = 0;
    highScore = 0; 
    lastUpdated = "";

    // user not found
    return false;
}

void Progress_data::saveProgress(int uid, int level, int lives, int gems, int score){

    db.readAllLines(PROGRESS_FILE);

    string newLine = to_string(uid) + "|" + to_string(level) + "|" + 
                    to_string(lives) + "|" + to_string(gems) + "|" + 
                    to_string(score) + "|" + getTodaysDate();

    string parts[6];
    int partCount = 0;
    bool recordFound = false;

    // replace existing line if found
    for(int i = 0; i < db.getCount(); i++)
    {
        splitstring(db.getLine(i), '|', parts, partCount);

        // replace old data
        if(partCount >= 6 && stoi(parts[0]) == uid)
        {
            db.setLine(i, newLine);
            recordFound = true;
            break;
        }
    }

    // if not found, add new line
    if(!recordFound)
    {
        db.appendLine(PROGRESS_FILE,newLine);
    }

    db.writeAllLines(PROGRESS_FILE);
    cout << "\n\nProgress saved successfully." << endl;

}

void Progress_data::updateGems(int uID, int gems){
    loadProgress(uID);
    saveProgress(uID, currentLevel, livesRemaining, gems, highScore);
}
void Progress_data::updateHighScore(int uID, int s){
    // s-score
    loadProgress(uID);
    saveProgress(uID, currentLevel, livesRemaining, gemCount, s);
}



//getters
int Progress_data::getCurrentLevel()    {
     return currentLevel; 
}
int Progress_data::getLivesRemaining()  {
    return livesRemaining; 
}
int Progress_data::getGemCount()  {
    return gemCount; 
}
int Progress_data::getHighScore()  {
    return highScore; 
}
string Progress_data::getLastUpdated()  {
    return lastUpdated; 
}
