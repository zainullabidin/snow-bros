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
                return GameState::PLAYING;
                powerUp = PowerUpType::SPEED_BOOST;
            }

            // snowball
            if (mousePos.x >= 450 && mousePos.x <= 574)
            {
                OnExit();
                return GameState::PLAYING;
                powerUp = PowerUpType::SNOWBALL_BOOST;
            }

            // distance increase
            if (mousePos.x >= 720 && mousePos.x <= 840)
            {
                OnExit();
                return GameState::PLAYING;
                powerUp = PowerUpType::DISTANCE_INCREASE;
            }

            // ballon mode
            if (mousePos.x >= 990 && mousePos.x <= 1114)
            {
                OnExit();
                return GameState::PLAYING;
                powerUp = PowerUpType::BALLOON_MODE;
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
