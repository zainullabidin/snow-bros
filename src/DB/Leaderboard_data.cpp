#include"../../include/DB/Leaderboard_data.h"

// constructor + destructor
Leaderboard::Leaderboard() : db(10) 
{
    db.createFileIfMissing(LEADERBOARD_FILE);
    entryCount = 0;
}
Leaderboard::~Leaderboard() {
    db.clear();
}


// ------- private methods --------

// simply sort descending
void Leaderboard::sort()
{
    for(int i = 0 ; i < entryCount - 1 ; i++)
    {
        // Compare adjacent elements, ignoring already-sorted elements at the end
        for(int j = 0 ; j < entryCount - i - 1; j++)
        {
            bool shouldSwap = false;

            if (score[j] < score[j+1]){
                shouldSwap = true;
            }
            else if (score[j] == score[j+1]){

                // same score, higher level wins
                if (levelReached[j] < levelReached[j+1]) 
                {
                    shouldSwap = true;
                }
            }

            if (shouldSwap)
            {
                // using helper functions
                swap(score[j], score[j+1]);
                swap(username[j], username[j+1]);
                swap(levelReached[j], levelReached[j+1]);
                swap(date[j], date[j+1]);
                swap(rank[j], rank[j+1]);
            }
        }
    }
}

void Leaderboard::reassignRanks()
{
    for(int i = 0 ; i < entryCount ; i++)
    {
        rank[i] = i + 1;
    }
}

// ------- public methods --------


void Leaderboard::getTopTen() 
{
    db.readAllLines(LEADERBOARD_FILE);

    entryCount = 0;
    string parts[5];
    int partCount = 0;

    for (int i = 0; i < db.getCount(); i++) 
    {
        splitstring(db.getLine(i), '|', parts, partCount);

        if (partCount >= 5 && entryCount < 10) 
        {
            rank[entryCount]         = stoi(parts[0]);
            username[entryCount]     = parts[1];
            score[entryCount]        = stoi(parts[2]);
            levelReached[entryCount] = stoi(parts[3]);
            date[entryCount]         = parts[4];
            entryCount++;
        }
    }
    sort();         // sort ALL of them after loading
    reassignRanks();// then reassign ranks
}

int Leaderboard::getLowestScore() const {
    if (entryCount == 0)
        return 0;
    
    return score[entryCount - 1];
}

bool Leaderboard::isTopTen(int score){
    if (entryCount < 10) return true;  // Less than 10 entries? Always top 10
    return score > getLowestScore();    // Exactly 10 entries? Compare with last
}

void Leaderboard::insertScore(const string& uname, int s, int level, const string& d)
{
    getTopTen(); // get current top ten scores

    username[entryCount] = uname;
    score[entryCount] = s;
    levelReached[entryCount] = level;
    date[entryCount] = d;
    entryCount++;

    sort();
    reassignRanks();

    if (entryCount > 10) entryCount = 10;
    
    db.clear();
    for (int i = 0; i < entryCount; i++)
    {
        string line = to_string(rank[i]) + "|" + username[i] 
                        + "|" + to_string(score[i]) + "|" + 
                        to_string(levelReached[i]) + "|" + date[i];
        
        db.appendLine(LEADERBOARD_FILE,line);
    }
    db.writeAllLines(LEADERBOARD_FILE);
    
}

// ------- getters --------
int Leaderboard::getRank(int i) const {
    return rank[i] ;
}
string Leaderboard::getUsername(int i) const {
    return username[i];
}
int Leaderboard::getScore(int i) const {
    return score[i];
}
int Leaderboard::getLevelReached(int i) const {
    return levelReached[i];
}
string Leaderboard::getDate(int i) const {
    return date[i];
}
int Leaderboard::getEntryCount() const {
    return entryCount;
}





// helper func
// function overloading
void swap(string & a, string & b){
    string temp = a;
    a = b;
    b = temp;
}

void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}