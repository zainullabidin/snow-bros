#include "../../include/DB/Leaderboard_data.h"

// constructor + destructor
Leaderboard::Leaderboard() : db(10)
{
    db.createFileIfMissing(LEADERBOARD_FILE);
    db.setCount(0);
}
Leaderboard::~Leaderboard()
{
    db.clear();
}

// ------- private methods --------

// simply sort descending
void Leaderboard::sort()
{
    db.readAllLines(LEADERBOARD_FILE);

    int allCount = db.getCount();
    // allocate based on actual file line count
    int *s = new int[allCount];
    int *l = new int[allCount];
    string *u = new string[allCount];
    string *d = new string[allCount];
    int *r = new int[allCount];

    string parts[5];
    int partCount = 0;
    int filled = 0;

    // fill ALL arrays properly from the existing file
    for (int i = 0; i < allCount; i++)
    {
        splitstring(db.getLine(i), '|', parts, partCount);
        if (partCount >= 5)
        {
            // no rank here, we'll set it after sorting at end 
            u[filled] = parts[1];
            s[filled] = stoi(parts[2]);
            l[filled] = stoi(parts[3]);
            d[filled] = parts[4];
            filled++;
        }
    }

    //  sort in descending
    for (int i = 0; i < filled - 1; i++)
    {
        // no need to check for already sorted part
        for (int j = 0; j < filled - i - 1; j++)
        {
            bool shouldSwap = false;

            // scores based swap
            if (s[j] < s[j + 1])
                shouldSwap = true;

            // if scores are equal, swap based on level reached
            else if (s[j] == s[j + 1])
                if (l[j] < l[j + 1])
                    shouldSwap = true;

            if (shouldSwap)
            {
                // using helper functions
                swap(s[j], s[j + 1]);
                swap(u[j], u[j + 1]);
                swap(l[j], l[j + 1]);
                swap(d[j], d[j + 1]);
            }
        }
    }

    // in ascending simply assign ranks + update lines
    for(int i = 0 ; i < filled ; i++)
    {
        r[i] = i + 1;
        db.setLine(i, to_string(r[i]) + "|" + u[i] + "|" + 
                to_string(s[i]) + "|" + to_string(l[i]) + "|" + d[i]);
    }

    // write updated data back to file
    db.writeAllLines(LEADERBOARD_FILE);

     
    // clear up memory
    delete[] s;
    delete[] l;
    delete[] u;
    delete[] d;
    s = nullptr;
    l = nullptr;
    u = nullptr;
    d = nullptr;
}




// ------- public methods --------

void Leaderboard::getTopTen()
{
    sort();          // sort the entries first
    db.readAllLines(LEADERBOARD_FILE);

    string parts[5];
    int partCount = 0;
    int filled = 0;

    // fill ALL arrays properly from the existing file just the 1st top ten
    for (int i = 0; i < 10; i++)
    {
        splitstring(db.getLine(i), '|', parts, partCount);
        if (partCount >= 5)
        {
            rank[filled] = stoi(parts[0]);
            username[filled] = parts[1];
            score[filled] = stoi(parts[2]);
            levelReached[filled] = stoi(parts[3]);
            date[filled] = parts[4];
            
            filled++;
        }
    }
}



void Leaderboard::insertScore(const string &uname, int s, int level, const string &d)
{
    // Read current data
    db.readAllLines(LEADERBOARD_FILE);
    
    // Check if user already exists
    string parts[5];
    int partCount = 0;
    bool userExists = false;

    // find location
    int existingScore = 0;
    int existingLevel = 0;
    int existingLineIndex = -1;
    
    for (int i = 0; i < db.getCount(); i++) 
    {
        splitstring(db.getLine(i), '|', parts, partCount);

        // finding the user and collecting data from it
        if (partCount >= 5 && parts[1] == uname) 
        {
            userExists = true;
            existingScore = stoi(parts[2]);
            existingLevel = stoi(parts[3]);
            existingLineIndex = i;
            break;
        }
    }
    

    if (userExists) {
        // If new score is higher, update the entry
        if (s > existingScore) 
        {
            // Remove the old line from db so if originally 14 now 13
            string *newLines = new string[db.getCount() - 1];  // 13 lines
            int newIdx = 0; 

            for (int i = 0; i < db.getCount(); i++) 
            {
                if (i != existingLineIndex)     // skip only the line we want to remove
                {
                    // others to new array
                    newLines[newIdx++] = db.getLine(i);
                }
            }
            
            db.clear();
            db.setCount(0);

            // reload the data back into original db obj 
            for (int i = 0; i < newIdx; i++) 
            {
                if (db.getCount() >= db.getCapacity()) 
                    db.resize();

                db.setLine(db.getCount(), newLines[i]);
                db.setCount(db.getCount() + 1);
            }

            delete[] newLines;
            newLines = nullptr;
            
            // Write the updated file without the old entry
            db.writeAllLines(LEADERBOARD_FILE);
            
            // Now add the new entry
            string line = to_string(db.getCount() + 1) + "|" + uname + "|" + to_string(s) + "|" + to_string(level) + "|" + d;
            db.appendLine(LEADERBOARD_FILE, line);
            
            // Sort and update top 10
            sort();
            getTopTen();
            return; // Exit here to prevent duplicate
        } 
        
        // New score is not higher, just keep existing line, no need to add new line
        else {
            sort();
            getTopTen();
            return; // Exit here too
        }
    }
    
    // User doesn't exist - add new entry normally
    if (db.getCount() >= db.getCapacity()) {
        db.resize();
    }
    
    string line = to_string(db.getCount() + 1) + "|" + uname + "|" + to_string(s) + "|" + to_string(level) + "|" + d;
    db.appendLine(LEADERBOARD_FILE, line);
    
    sort();
    getTopTen();
}

// ------- getters --------
int Leaderboard::getRank(int i) const
{
    return rank[i];
}
string Leaderboard::getUsername(int i) const
{
    return username[i];
}
int Leaderboard::getScore(int i) const
{
    return score[i];
}
int Leaderboard::getLevelReached(int i) const
{
    return levelReached[i];
}
string Leaderboard::getDate(int i) const
{
    return date[i];
}

// helper func
// function overloading
void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}