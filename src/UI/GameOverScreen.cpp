#include"../../include/UI/GameOverScreen.h"


// constructor

GameOverScreen::GameOverScreen() {
    loadBackground("assets/Images/gameOver.jpeg");
    // loadBackgroundMusic("../../assets/Sounds/gameOver.mp3");     // sound
    // playMusic();
    
    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);
}
GameOverScreen::~GameOverScreen() {}

GameState GameOverScreen::Update(float deltaTime, RenderWindow& window)
{	
    // Check for mouse click
    if (Mouse::isButtonPressed(Mouse::Left)) 
    {
        Vector2i mousePos = Mouse::getPosition(window);
        
        // Check if click is within button bounds
        if (mousePos.x >= 364 && mousePos.x <= 664 &&  // 364 + 300
            mousePos.y >= 347 && mousePos.y <= 407)     // 347 + 60
        {  
            OnExit();
            return GameState::MAIN_MENU;
        }
    }
    
    // Return current state if no button clicked
    return GameState::GAME_OVER;  
}

void GameOverScreen::OnActivate() {
    playMusic();
}


void GameOverScreen::draw(RenderWindow& window) {
    window.draw(backgroundSprite);
}

void GameOverScreen::OnExit() {
    stopMusic();
}
