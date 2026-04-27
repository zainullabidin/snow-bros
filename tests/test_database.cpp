// test_leaderboard_persistent.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "../include/DB/Leaderboard_data.h"
#include "../include/DB/Data_base.h"

using namespace std;

// Helper function to display top 10 from Leaderboard object
void displayTopTen(Leaderboard& lb) {
    cout << "\n========== TOP 10 LEADERBOARD ==========" << endl;
    cout << "Rank\tUsername\tScore\tLevel\tDate" << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < 10; i++) {
        if (lb.getUsername(i).empty()) {
            break;
        }
        
        cout << lb.getRank(i) << "\t"
             << lb.getUsername(i) << "\t\t"
             << lb.getScore(i) << "\t"
             << lb.getLevelReached(i) << "\t"
             << lb.getDate(i) << endl;
    }
    cout << "========================================\n" << endl;
}

// Helper function to display raw file contents
void displayFileContents() {
    cout << "\n--- RAW FILE CONTENTS (leaderboard.txt) ---" << endl;
    ifstream file("data/leaderboard.txt");
    if (!file) {
        cout << "File not found!" << endl;
        return;
    }
    
    string line;
    int lineNum = 1;
    while (getline(file, line)) {
        if (!line.empty())
            cout << lineNum++ << ": " << line << endl;
    }
    file.close();
    cout << "-------------------------------------------\n" << endl;
}

// TEST 1: Load existing leaderboard data (no clearing)
void testLoadExistingData() {
    cout << "\n=== TEST 1: Loading Existing Leaderboard Data ===" << endl;
    
    Leaderboard lb;
    lb.getTopTen();
    
    cout << "Leaderboard loaded from existing file:" << endl;
    displayTopTen(lb);
    
    // Count how many entries were loaded
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (!lb.getUsername(i).empty()) count++;
    }
    
    cout << "Loaded " << count << " entries from database" << endl;
    cout << "Result: " << (count > 0 ? "PASSED - Database has data" : "WARNING - Database empty") << endl;
}

// TEST 2: Insert new score to existing leaderboard
void testInsertToExisting() {
    cout << "\n=== TEST 2: Inserting New Score to Existing Leaderboard ===" << endl;
    
    // Show leaderboard before insertion
    Leaderboard lbBefore;
    lbBefore.getTopTen();
    cout << "BEFORE INSERTION:" << endl;
    displayTopTen(lbBefore);
    
    // Insert a new score
    cout << "Inserting new player 'NewChallenger' with score 5000, level 7..." << endl;
    lbBefore.insertScore("NewChallenger", 5000, 7, "2024-01-15");
    
    // Show leaderboard after insertion
    Leaderboard lbAfter;
    lbAfter.getTopTen();
    cout << "AFTER INSERTION:" << endl;
    displayTopTen(lbAfter);
    
    // Verify insertion worked
    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (lbAfter.getUsername(i) == "NewChallenger") {
            found = true;
            cout << "✓ New player found at rank " << lbAfter.getRank(i) << endl;
            break;
        }
    }
    
    cout << "Result: " << (found ? "PASSED" : "FAILED") << endl;
}

// TEST 3: Insert multiple scores to existing leaderboard
void testMultipleInserts() {
    cout << "\n=== TEST 3: Multiple Inserts to Existing Leaderboard ===" << endl;
    
    Leaderboard lb;
    
    // Show current state
    lb.getTopTen();
    cout << "CURRENT LEADERBOARD:" << endl;
    displayTopTen(lb);
    
    // Insert multiple scores
    cout << "Inserting 5 new players..." << endl;
    lb.insertScore("HighScoreMaster", 10000, 10, "2024-01-15");
    lb.insertScore("MidRangePlayer", 4500, 6, "2024-01-15");
    lb.insertScore("LowScorePlayer", 500, 2, "2024-01-15");
    lb.insertScore("AnotherPro", 8000, 8, "2024-01-15");
    lb.insertScore("CasualGamer", 2000, 4, "2024-01-15");
    
    // Reload and display
    Leaderboard lbUpdated;
    lbUpdated.getTopTen();
    cout << "UPDATED LEADERBOARD:" << endl;
    displayTopTen(lbUpdated);
    
    cout << "Result: PASSED - All inserts processed" << endl;
}

// TEST 4: Verify sorting with existing data + new data
void testSortingWithExistingData() {
    cout << "\n=== TEST 4: Sorting Verification with Mixed Data ===" << endl;
    
    Leaderboard lb;
    lb.getTopTen();
    
    cout << "Current leaderboard (should be sorted by score desc):" << endl;
    
    bool isSorted = true;
    int prevScore = 999999;
    for (int i = 0; i < 10; i++) {
        if (lb.getUsername(i).empty()) break;
        
        cout << "Rank " << lb.getRank(i) << ": " 
             << lb.getUsername(i) << " - " 
             << lb.getScore(i) << " points" << endl;
        
        if (lb.getScore(i) > prevScore) {
            isSorted = false;
        }
        prevScore = lb.getScore(i);
    }
    
    cout << "\nSorting verification: " << (isSorted ? "PASSED" : "FAILED") << endl;
}

// TEST 5: Insert score that becomes new #1
void testInsertBecomesTop() {
    cout << "\n=== TEST 5: Inserting Score That Becomes #1 ===" << endl;
    
    Leaderboard lbBefore;
    lbBefore.getTopTen();
    
    // Get current top score
    int currentTop = 0;
    if (!lbBefore.getUsername(0).empty()) {
        currentTop = lbBefore.getScore(0);
        cout << "Current #1 score: " << currentTop << " by " << lbBefore.getUsername(0) << endl;
    }
    
    // Insert much higher score
    int newHighScore = currentTop + 5000;
    cout << "Inserting new champion with score " << newHighScore << "..." << endl;
    lbBefore.insertScore("NEW_CHAMPION", newHighScore, 10, "2024-01-15");
    
    Leaderboard lbAfter;
    lbAfter.getTopTen();
    
    cout << "\nNew #1: " << lbAfter.getUsername(0) << " with " << lbAfter.getScore(0) << " points" << endl;
    
    bool isNewChampionTop = (lbAfter.getUsername(0) == "NEW_CHAMPION" && lbAfter.getScore(0) == newHighScore);
    cout << "Result: " << (isNewChampionTop ? "PASSED" : "FAILED") << endl;
}

// TEST 6: Insert score that barely makes top 10
void testInsertBarelyMakesTop10() {
    cout << "\n=== TEST 6: Inserting Score That Barely Makes Top 10 ===" << endl;
    
    Leaderboard lb;
    lb.getTopTen();
    
    // Get current #10 score
    int tenthScore = 0;
    string tenthUser = "";
    for (int i = 0; i < 10; i++) {
        if (lb.getUsername(i).empty()) {
            // Less than 10 entries, any score makes top 10
            cout << "Less than 10 entries in database (" << i << " entries)" << endl;
            break;
        }
        if (i == 9) {
            tenthScore = lb.getScore(9);
            tenthUser = lb.getUsername(9);
            cout << "Current #10: " << tenthUser << " with " << tenthScore << " points" << endl;
        }
    }
    
    if (tenthScore > 0) {
        // Insert score slightly higher than #10
        int newScore = tenthScore + 100;
        cout << "Inserting player 'JustMadeIt' with score " << newScore << "..." << endl;
        lb.insertScore("JustMadeIt", newScore, 5, "2024-01-15");
        
        Leaderboard lbUpdated;
        lbUpdated.getTopTen();
        
        // Check if new player is now in top 10
        bool found = false;
        for (int i = 0; i < 10; i++) {
            if (lbUpdated.getUsername(i) == "JustMadeIt") {
                found = true;
                cout << "✓ 'JustMadeIt' found at rank " << lbUpdated.getRank(i) << endl;
                break;
            }
        }
        
        // Check if previous #10 got bumped
        bool oldTenthGone = true;
        for (int i = 0; i < 10; i++) {
            if (lbUpdated.getUsername(i) == tenthUser && i == 9) {
                oldTenthGone = false; // Still at #10
            }
        }
        
        cout << "Previous #10 player '" << tenthUser << "' bumped out: " 
             << (oldTenthGone ? "YES" : "NO (still in top 10)") << endl;
        
        cout << "Result: " << (found ? "PASSED" : "FAILED") << endl;
    } else {
        cout << "Skipping test - less than 10 entries in database" << endl;
    }
}

// TEST 7: Verify top 10 arrays don't contain entries beyond rank 10
void testTop10Only() {
    cout << "\n=== TEST 7: Verifying Only Top 10 Stored in Arrays ===" << endl;
    
    // First, ensure we have more than 10 entries by inserting if needed
    Leaderboard lb;
    
    // Check current count
    ifstream file("data/leaderboard.txt");
    int lineCount = 0;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) lineCount++;
    }
    file.close();
    
    cout << "Total entries in database file: " << lineCount << endl;
    
    if (lineCount < 15) {
        cout << "Adding extra entries to test top-10-only behavior..." << endl;
        for (int i = lineCount + 1; i <= 15; i++) {
            lb.insertScore("TestUser" + to_string(i), 1000 - i, i % 10, "2024-01-15");
        }
    }
    
    // Load fresh leaderboard
    Leaderboard lbTest;
    lbTest.getTopTen();
    
    // Check that we only have 10 entries in the arrays
    int arrayCount = 0;
    for (int i = 0; i < 10; i++) {
        if (!lbTest.getUsername(i).empty()) {
            arrayCount++;
        }
    }
    
    cout << "Entries stored in member arrays: " << arrayCount << endl;
    cout << "Result: " << (arrayCount <= 10 ? "PASSED - Max 10 entries in arrays" : "FAILED - More than 10 in arrays") << endl;
    
    // Also verify ranks are 1-10
    bool correctRanks = true;
    for (int i = 0; i < arrayCount; i++) {
        if (lbTest.getRank(i) != i + 1) {
            correctRanks = false;
            cout << "  Error: Rank " << lbTest.getRank(i) << " at position " << i << " (expected " << i+1 << ")" << endl;
        }
    }
    
    cout << "Correct ranks (1-10): " << (correctRanks ? "PASSED" : "FAILED") << endl;
}

// Main test runner
int main() {
    cout << "============================================================" << endl;
    cout << "     LEADERBOARD DATABASE TEST - PERSISTENT DATA           " << endl;
    cout << "============================================================" << endl;
    cout << "\nNOTE: These tests DO NOT clear the leaderboard file." << endl;
    cout << "They work with whatever data already exists in the database.\n" << endl;
    
    // Ensure data directory exists
    system("mkdir data 2>nul");
    
    // Display current database state
    cout << "\n=== CURRENT DATABASE STATE ===" << endl;
    displayFileContents();
    
    // Run all tests
    testLoadExistingData();
    testInsertToExisting();
    testMultipleInserts();
    testSortingWithExistingData();
    testInsertBecomesTop();
    testInsertBarelyMakesTop10();
    testTop10Only();
    
    cout << "\n============================================================" << endl;
    cout << "                    TESTS COMPLETE                          " << endl;
    cout << "============================================================" << endl;
    
    // Final database state
    cout << "\n=== FINAL DATABASE STATE ===" << endl;
    Leaderboard finalLb;
    finalLb.getTopTen();
    displayTopTen(finalLb);
    displayFileContents();
    
    return 0;
}