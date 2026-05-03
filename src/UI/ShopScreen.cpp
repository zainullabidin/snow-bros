#include "../../include/UI/ShopScreen.h"

// constructor

ShopScreen::ShopScreen()
{
    loadBackground("assets/Images/Shop.png");
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

if(mousePos.x >= 24 && mousePos.x <= 334 && mousePos.y >= 29 && mousePos.y <= 116)
{

    OnExit();
    return GameState::MAIN_MENU;
}

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
                
                //adde main_menu check
            }



        }
    }


    powerUp = PowerUpType::NONE;
    // Return current state if no button clickedx
    return GameState::SHOP;

}

void ShopScreen::OnActivate()
{
    playMusic();
}

void ShopScreen::draw(RenderWindow &window)
{

      window.draw(backgroundSprite);

      sf::Font font;
    font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf");
    sf::Text coinText;
    coinText.setFont(font);
    coinText.setString(to_string(coins));
    coinText.setCharacterSize(25);
    coinText.setFillColor(sf::Color::Yellow);
    coinText.setPosition(1200, 80);
    window.draw(coinText);
    

}

void ShopScreen::OnExit()
{
    stopMusic();
}

void ShopScreen::set_coins(int c)
{
     coins = c; 
 }


