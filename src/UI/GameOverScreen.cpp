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
        if (mousePos.x >= 350 && mousePos.x <= 830 &&  // 364 + 300
            mousePos.y >= 430 && mousePos.y <= 515)     // 347 + 60
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
