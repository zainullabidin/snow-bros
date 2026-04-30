#include "../../include/UI/StarScreen.h"
#include "../../include/UI/StarScreen.h"

// constructor

StarScreen::StarScreen()
{

    srand(time(0)); // need to do it in main game loop

    loadBackground("assets/Images/StarEvent.png");
    // loadBackgroundMusic("../../assets/Sounds/gameOver.mp3");     // sound
    // playMusic();

    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);
    // sprites
    int sprite_state = rand() % 5 + 1;

    // Load 3 unique random textures and powerUp_states
    loadRandomItems();

    for (int i = 0; i < 3; i++)
    {
        sprites[i].setPosition(160 + i * 400, 330);
        sprites[i].setScale(0.4f, 0.4f);
    }
}
StarScreen::~StarScreen() {}

GameState StarScreen::Update(float deltaTime, RenderWindow &window)
{
    PowerUpType powerUp = PowerUpType::NONE;
    return Update(deltaTime, window, powerUp);
}

GameState StarScreen::Update(float deltaTime, RenderWindow &window, PowerUpType &powerUp)
{

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        // get mouse pos
        Vector2i mousePos = Mouse::getPosition(window);

        // Check each star's click area
        for (int i = 0; i < 3; i++)
        {
            // areaa of spritee
            FloatRect bounds = sprites[i].getGlobalBounds();

            if (bounds.contains(mousePos.x, mousePos.y))
            {
                powerUp = powerUpTypes[i]; // Set the power-up
                OnExit();
                return GameState::PLAYING;
            }
        }
    }

    return GameState::SHOP; // Stay in shop if no star clicked
}

// load random 3 powerUps

void StarScreen::loadRandomItems()
{
    // all images
    string starFiles[5] =
        {
            "assets/Images/speedboost.png",
            "assets/Images/snowball.png",
            "assets/Images/distanceInc.png",
            "assets/Images/baloon.png",
            "assets/Images/newlife.png"
        };

    // All available power-ups
    PowerUpType allPowerUps[] = {
        PowerUpType::SPEED_BOOST,
        PowerUpType::SNOWBALL_BOOST,
        PowerUpType::DISTANCE_INCREASE,
        PowerUpType::BALLOON_MODE,
        PowerUpType::EXTRA_LIFE
    };

    // Track which indices have been used
    bool used[5] = {false};

    // Load 3 unique random textures
    for (int i = 0; i < 3; i++)
    {
        int randomIndex;
        do
        {
            randomIndex = rand() % 5;
        } while (used[randomIndex]); // Keep trying until we find unused index

        used[randomIndex] = true; // Mark as used

        // Load the texture
        if (!textures[i].loadFromFile(starFiles[randomIndex]))
        {
            cout << "Unable to load powerUp " << i + 1 << ": " << starFiles[randomIndex] << endl;
        }
        else
        {
            sprites[i].setTexture(textures[i]);

            // Store the matching power-up
            powerUpTypes[i] = allPowerUps[randomIndex];
        }
    }
}



void StarScreen::OnActivate()
{
    playMusic();
}

void StarScreen::draw(RenderWindow &window)
{
    window.draw(backgroundSprite);

    // Draw all 3 random sprites
    for (int i = 0; i < 3; i++)
    {
        window.draw(sprites[i]);
    }
}

void StarScreen::OnExit()
{
    stopMusic();
}
