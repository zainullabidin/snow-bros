#pragma once

#include "../main/Game_state.h"
#include "../DB/Leaderboard_data.h"
#include"Screen.h"
using namespace sf;
using namespace std;

class LeaderboardScreen : public Screen
{

    Leaderboard leaderboard;
    Font font;
    int entryCount = 0;

    // enteries
    Text nameTexts[10];
    Text scoreTexts[10];
    Text levelTexts[10];
    Text dateTexts[10];

public:
    LeaderboardScreen();
    ~LeaderboardScreen();
    
    GameState Update(float deltaTime, RenderWindow& window) override;
    void OnActivate() override;
    void draw(RenderWindow& window) override;
    void OnExit() override;
    void refreshDisplay();
    
};