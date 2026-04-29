#include"../../include/UI/LeaderboardScreen.h"

// constructor

LeaderboardScreen::LeaderboardScreen() {
    loadBackground("assets/Images/leaderboard.png");
    // loadBackgroundMusic("../../assets/Sounds/gameOver.mp3");     // sound
    // playMusic();
    
    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);


    if (!font.loadFromFile("assets/fonts/Orbitron-VariableFont_wght.ttf")) { // Load font
        cout << "Error: Failed to load font." << endl;
        return;
    }
    

    // set font characteristics
    for(int i = 0 ;  i < 12 ; i++)
    {
        nameTexts[i].setFont(font);
        nameTexts[i].setCharacterSize(12);
        nameTexts[i].setFillColor(sf::Color::White);    

        scoreTexts[i].setFont(font);
        scoreTexts[i].setCharacterSize(12);
        scoreTexts[i].setFillColor(sf::Color::Cyan);    

        levelTexts[i].setFont(font);
        levelTexts[i].setCharacterSize(12);
        levelTexts[i].setFillColor(sf::Color::White);    

        dateTexts[i].setFont(font);
        dateTexts[i].setCharacterSize(12);
        dateTexts[i].setFillColor(sf::Color::White);    

    }

}
LeaderboardScreen::~LeaderboardScreen() {}

// Update logic, exit iogic
GameState LeaderboardScreen::Update(float deltaTime, RenderWindow& window)
{	
    // Check for mouse click
    if (Mouse::isButtonPressed(Mouse::Left)) 
    {
        Vector2i mousePos = Mouse::getPosition(window);
        
        // Check if click is within button bounds
        if (mousePos.x >= 940 && mousePos.x <= 1177 &&  // 364 + 300
            mousePos.y >= 560 && mousePos.y <= 640)     // 347 + 60
        { 
            OnExit();
            return GameState::MAIN_MENU;
        }
    }
    
    // Return current state if no button clicked
    return GameState::LEADERBOARD;  
}


// adding enterires
void LeaderboardScreen::refreshDisplay() 
{
    leaderboard.getTopTen();
    entryCount = 0;

    // setting pos
    int nameX = 235;
    int scoreX = 418;
    int levelX = 525;
    int dateX = 613;



    for (int i = 0 ; i < 10 ; i++) 
    {
        // line by line
        string username = leaderboard.getUsername(i);

        // no entry
        if (username.empty()) {
            break;
        }

        // y pos
        int yPos = 250 + (i * 36);

        // Username
        nameTexts[entryCount].setString(username);
        nameTexts[entryCount].setPosition(nameX, yPos);

        // Score
        scoreTexts[entryCount].setString(to_string(leaderboard.getScore(i)));
        scoreTexts[entryCount].setPosition(scoreX, yPos);

        // Level
        levelTexts[entryCount].setString(to_string(leaderboard.getLevelReached(i)));
        levelTexts[entryCount].setPosition(levelX, yPos);

        // Date
        dateTexts[entryCount].setString(leaderboard.getDate(i));
        dateTexts[entryCount].setPosition(dateX, yPos);

        entryCount++;
    }


}

void LeaderboardScreen::OnActivate() {
    // playMusic();             // on when audio attached
    refreshDisplay();
}


void LeaderboardScreen::draw(RenderWindow& window) {
    window.draw(backgroundSprite);

    for(int i = 0 ;  i < entryCount ; i++)
    {
        window.draw(nameTexts[i]);
        window.draw(scoreTexts[i]);
        window.draw(levelTexts[i]);
        window.draw(dateTexts[i]);
    }
}

void LeaderboardScreen::OnExit() {
    stopMusic();
    entryCount = 0;
}
