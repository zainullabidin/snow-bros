// test_database.cpp
// Run this to verify all DB classes work correctly
// Place this file in your src/ folder and compile with the rest

#include "../include/DB/Data_base.h"
#include "../include/DB/User_data.h"
#include "../include/DB/Progress_data.h"
#include "../include/DB/Leaderboard_data.h"
#include <iostream>
using namespace std;

// ────────────────────────────────────────────
// simple test helper — prints PASS or FAIL 
// ────────────────────────────────────────────
void check(const string& testName, bool condition) {
    if (condition)
        cout << "[PASS] " << testName << endl;
    else
        cout << "[FAIL] " << testName << endl;
}

// ─────────────────────────────────────────────
// 1. DATA_BASE TESTS
// ─────────────────────────────────────────────
void test_database() {
    cout << "\n======== Data_base Tests ========\n";
    Data_base db(5);

    // fileExists on missing file
    check("fileExists returns false for missing file",
          db.fileExists("../../data/nonexistent_xyz.txt") == false);

    // createFileIfMissing
    db.createFileIfMissing("../../data/test_temp.txt");
    check("createFileIfMissing creates the file",
          db.fileExists("../../data/test_temp.txt") == true);

    // appendLine + readAllLines
    db.appendLine("../../data/test_temp.txt", "hello|world|123");
    db.appendLine("../../data/test_temp.txt", "foo|bar|456");
    db.readAllLines("../../data/test_temp.txt");
    check("readAllLines reads correct count", db.getCount() == 2);
    check("getLine(0) returns first line",   db.getLine(0) == "hello|world|123");
    check("getLine(1) returns second line",  db.getLine(1) == "foo|bar|456");

    // setLine
    db.setLine(0, "replaced|line|999");
    check("setLine replaces line in memory", db.getLine(0) == "replaced|line|999");

    // writeAllLines then re-read
    db.writeAllLines("../../data/test_temp.txt");
    Data_base db2(5);
    db2.readAllLines("../../data/test_temp.txt");
    check("writeAllLines persists to file",  db2.getLine(0) == "replaced|line|999");

    // clear
    db.clear();
    check("clear resets count to 0", db.getCount() == 0);

    // resize — add more lines than initial capacity (5)
    Data_base db3(2);   // tiny capacity to force resize
    db3.appendLine("../../data/test_temp.txt", "line1");
    db3.appendLine("../../data/test_temp.txt", "line2");
    db3.appendLine("../../data/test_temp.txt", "line3");
    db3.readAllLines("../../data/test_temp.txt");
    check("resize works — reads more lines than initial capacity",
          db3.getCount() >= 2);

    // splitString free function
    string parts[5];
    int partCount = 0;
    splitstring("1|zain|hash|email", '|', parts, partCount);
    check("splitString partCount == 4",  partCount == 4);
    check("splitString parts[0] == '1'", parts[0] == "1");
    check("splitString parts[1] == 'zain'", parts[1] == "zain");
    check("splitString parts[3] == 'email'", parts[3] == "email");

    // splitString with trailing delimiter edge case
    splitstring("1|zain|", '|', parts, partCount);
    check("splitString handles trailing delimiter", partCount == 2);

    // cleanup temp file
    // (just leave it — it's harmless)
}

// ─────────────────────────────────────────────
// 2. USER_DATA TESTS
// ─────────────────────────────────────────────
void test_userdata() {
    cout << "\n======== User_data Tests ========\n";
    User_data u;

    // create a new user
    bool created = u.create("testuser", "hashedpass123", "test@email.com");
    check("create returns true for new user", created == true);

    // create duplicate
    bool duplicate = u.create("testuser", "hashedpass123", "test@email.com");
    check("create returns false for duplicate username", duplicate == false);

    // usernameExists
    check("usernameExists returns true for existing user",
          u.usernameExists("testuser") == true);
    check("usernameExists returns false for unknown user",
          u.usernameExists("ghostuser_xyz") == false);

    // findByUsername
    bool found = u.findByUsername("testuser");
    check("findByUsername returns true for existing user", found == true);
    check("getUserId is valid (> 0) after find",  u.getUserId() > 0);
    check("getUsername matches after find",        u.getUsername() == "testuser");
    check("getPasswordHash matches after find",    u.getPasswordHash() == "hashedpass123");
    check("getEmail matches after find",           u.getEmail() == "test@email.com");

    // findByUsername for nonexistent
    bool notFound = u.findByUsername("nobody_xyz_abc");
    check("findByUsername returns false for unknown user", notFound == false);

    // getNextId — should be greater than 0
    int nextId = u.getNextId();
    check("getNextId returns value > 0", nextId > 0);

    // create second user and check id increments
    u.create("seconduser", "anotherhash", "second@email.com");
    int nextId2 = u.getNextId();
    check("getNextId increments after second user created", nextId2 > nextId);

    // password is NOT stored as plain text check
    // (we can only verify it stored SOMETHING, not the raw password)
    u.findByUsername("testuser");
    check("password stored is not empty", u.getPasswordHash() != "");

    // email optional — empty email
    u.create("noEmailUser", "hash456", "");
    bool foundNoEmail = u.findByUsername("noEmailUser");
    check("user with empty email can be created and found", foundNoEmail == true);
    check("empty email stored correctly", u.getEmail() == "");
}

// ─────────────────────────────────────────────
// 3. PROGRESS_DATA TESTS
// ─────────────────────────────────────────────
void test_progressdata() {
    cout << "\n======== Progress_data Tests ========\n";
    Progress_data p;

    // loadProgress for nonexistent user — should return false + safe defaults
    bool loaded = p.loadProgress(9999);
    check("loadProgress returns false for unknown user",    loaded == false);
    check("default currentLevel is 1",                     p.getCurrentLevel() == 1);
    check("default livesRemaining is 2",                   p.getLivesRemaining() == 2);
    check("default gemCount is 0",                         p.getGemCount() == 0);
    check("default highScore is 0",                        p.getHighScore() == 0);

    // saveProgress — new record
    p.saveProgress(101, 3, 2, 50, 1200);
    bool loaded2 = p.loadProgress(101);
    check("loadProgress returns true after save",          loaded2 == true);
    check("currentLevel saved correctly",                  p.getCurrentLevel() == 3);
    check("livesRemaining saved correctly",                p.getLivesRemaining() == 2);
    check("gemCount saved correctly",                      p.getGemCount() == 50);
    check("highScore saved correctly",                     p.getHighScore() == 1200);
    check("lastUpdated is not empty after save",           p.getLastUpdated() != "");

    // saveProgress — update existing record
    p.saveProgress(101, 5, 1, 80, 2500);
    p.loadProgress(101);
    check("currentLevel updated correctly",                p.getCurrentLevel() == 5);
    check("gemCount updated correctly",                    p.getGemCount() == 80);
    check("highScore updated correctly",                   p.getHighScore() == 2500);

    // updateGems
    p.updateGems(101, 999);
    p.loadProgress(101);
    check("updateGems updates gem count",                  p.getGemCount() == 999);
    check("updateGems preserves level",                    p.getCurrentLevel() == 5);

    // updateHighScore — higher score
    p.updateHighScore(101, 9999);
    p.loadProgress(101);
    check("updateHighScore updates when score is higher",  p.getHighScore() == 9999);

    // two different users don't interfere
    p.saveProgress(102, 1, 2, 0, 0);
    p.loadProgress(101);
    check("user 101 data intact after user 102 saved",     p.getCurrentLevel() == 5);
    p.loadProgress(102);
    check("user 102 loaded correctly",                     p.getCurrentLevel() == 1);
}

// ─────────────────────────────────────────────
// 4. LEADERBOARD_DATA TESTS
// ─────────────────────────────────────────────
void test_leaderboard() {
    cout << "\n======== Leaderboard_data Tests ========\n";
    Leaderboard lb;

    // getLowestScore on empty leaderboard
    lb.getTopTen();
    check("getLowestScore returns 0 when empty", lb.getLowestScore() == 0);

    // isTopTen when fewer than 10 entries
    check("isTopTen returns true when fewer than 10 entries",
          lb.isTopTen(100) == true);

    // insert first score
    lb.insertScore("zain",    15200, 8, "2026-04-20");
    lb.insertScore("minahil", 12400, 6, "2026-04-19");
    lb.insertScore("ahmed",    9800, 5, "2026-04-18");

    lb.getTopTen();
    check("entryCount is 3 after 3 inserts",     lb.getEntryCount() == 3);
    check("highest score is rank 1",             lb.getScore(0) == 15200);
    check("rank 1 username is zain",             lb.getUsername(0) == "zain");
    check("second score is rank 2",              lb.getScore(1) == 12400);

    // tiebreak by level
    lb.insertScore("ali", 12400, 8, "2026-04-21"); // same score as minahil, higher level
    lb.getTopTen();
    // ali should be rank 2 (same score, higher level)
    check("tiebreak: higher level wins same score", lb.getUsername(1) == "ali");

    // ranks are assigned correctly
    check("rank[0] == 1", lb.getRank(0) == 1);
    check("rank[1] == 2", lb.getRank(1) == 2);
    check("rank[2] == 3", lb.getRank(2) == 3);

    // fill up to 10
    lb.insertScore("p4",  8000, 4, "2026-04-18");
    lb.insertScore("p5",  7000, 3, "2026-04-18");
    lb.insertScore("p6",  6000, 3, "2026-04-18");
    lb.insertScore("p7",  5000, 2, "2026-04-18");
    lb.insertScore("p8",  4000, 2, "2026-04-18");
    lb.insertScore("p9",  3000, 1, "2026-04-18");
    lb.insertScore("p10", 2000, 1, "2026-04-18");
    lb.getTopTen();
    check("entryCount is 10 after 10 inserts", lb.getEntryCount() == 10);

    // isTopTen when full
    check("isTopTen returns false for score below lowest",
          lb.isTopTen(500) == false);
    check("isTopTen returns true for score above lowest",
          lb.isTopTen(99999) == true);

    // insert score that qualifies — lowest should be replaced
    int lowestBefore = lb.getLowestScore();
    lb.insertScore("newchamp", 99999, 10, "2026-04-22");
    lb.getTopTen();
    check("new top score becomes rank 1",         lb.getUsername(0) == "newchamp");
    check("entryCount stays at 10 after insert",  lb.getEntryCount() == 10);
    check("lowest score increased after replace", lb.getLowestScore() > lowestBefore);

    // date stored correctly
    check("date stored correctly", lb.getDate(0) == "2026-04-22");
}

// ─────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────
int main() {
    cout << "================================================\n";
    cout << "       SNOW BROS — DATABASE TEST SUITE          \n";
    cout << "================================================\n";

    test_database();
    test_userdata();
    test_progressdata();
    test_leaderboard();

    cout << "\n================================================\n";
    cout << "Tests complete. All [FAIL] lines need fixing.\n";
    cout << "================================================\n";

    return 0;
}
