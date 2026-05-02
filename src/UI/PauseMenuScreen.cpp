#include"../../include/UI/PauseMenuScreen.h"


// constructor

PauseMenuScreen::PauseMenuScreen() {
    loadBackground("assets/Images/PauseMenu.png");
    // loadBackgroundMusic("../../assets/Sounds/gameOver.mp3");     // sound
    // playMusic();
    
    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);
}
PauseMenuScreen::~PauseMenuScreen() {}

GameState PauseMenuScreen::Update(float deltaTime, RenderWindow& window)
{	
    // Check for mouse click
    if (Mouse::isButtonPressed(Mouse::Left)) 
    {
        Vector2i mousePos = Mouse::getPosition(window);
        
        // Check if click is on main menu
        if (mousePos.x >= 460 && mousePos.x <= 835 &&  // 364 + 300
            mousePos.y >= 550 && mousePos.y <= 632)     // 347 + 60
        {  
            OnExit();
            return GameState::MAIN_MENU;
        }

        if (mousePos.x >= 460 && mousePos.x <= 830 &&  // 364 + 300
            mousePos.y >= 440 && mousePos.y <= 515)     // 347 + 60
        {  
            OnExit();
            return GameState::PLAYING;
        }

    }
    
    // Return current state if no button clicked
    return GameState::PAUSED;  
}

void PauseMenuScreen::OnActivate() {
    playMusic();
}


void PauseMenuScreen::draw(RenderWindow& window) {
        if (backgroundSprite.getTexture() == nullptr) {

    } else {
        sf::Vector2u texSize = backgroundSprite.getTexture()->getSize();

        
        sf::Vector2f pos = backgroundSprite.getPosition();
        sf::Vector2f scale = backgroundSprite.getScale();
     
    }
    
    window.draw(backgroundSprite);
}

void PauseMenuScreen::OnExit() {
    stopMusic();
}



