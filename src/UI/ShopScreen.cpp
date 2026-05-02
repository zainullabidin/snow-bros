#include "../../include/UI/ShopScreen.h"

// constructor

ShopScreen::ShopScreen()
{
    loadBackground("assets/Images/Shop.jpeg");
    // loadBackgroundMusic("../../assets/Sounds/gameOver.mp3");     // sound
    // playMusic();

    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);
}
ShopScreen::~ShopScreen() {}


GameState ShopScreen::Update(float deltaTime, RenderWindow &window)
{
    PowerUpType powerUp = PowerUpType::NONE;
    return Update(deltaTime, window, powerUp);
}

GameState ShopScreen::Update(float deltaTime, RenderWindow &window, PowerUpType &powerUp)
{
    powerUp = PowerUpType::NONE;
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i mousePos = Mouse::getPosition(window);

        if (mousePos.y >= 590 && mousePos.y <= 660)
        {
            // speed boost
            if (mousePos.x >= 180 && mousePos.x <= 300)
            {
                OnExit();
                powerUp = PowerUpType::SPEED_BOOST;
                return GameState::PLAYING;
                
            }

            // snowball
            if (mousePos.x >= 450 && mousePos.x <= 574)
            {
                OnExit();
                 powerUp = PowerUpType::SNOWBALL_BOOST;
                return GameState::PLAYING;
               
            }

            // distance increase
            if (mousePos.x >= 720 && mousePos.x <= 840)
            {
                OnExit();
                powerUp = PowerUpType::DISTANCE_INCREASE;
                return GameState::PLAYING;
                
            }

            // ballon mode
            if (mousePos.x >= 990 && mousePos.x <= 1114)
            {
                OnExit();
                powerUp = PowerUpType::BALLOON_MODE;
                return GameState::PLAYING;
                
            }
        }
    }

    powerUp = PowerUpType::NONE;
    // Return current state if no button clicked
    return GameState::SHOP;

}

void ShopScreen::OnActivate()
{
    playMusic();
}

void ShopScreen::draw(RenderWindow &window)
{
    window.draw(backgroundSprite);
}

void ShopScreen::OnExit()
{
    stopMusic();
}
