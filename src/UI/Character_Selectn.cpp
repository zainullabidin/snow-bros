#include"../../include/UI/Character_Selectn.h"


// constructor

CharacterSelect::CharacterSelect()
{
    selectedCharacter = 1;

    loadBackground("assets/Images/CutieCharacters.png");
    // loadBackgroundMusic("../../assets/Sounds/gameOver.mp3");     // sound
    // playMusic();

    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);
}

CharacterSelect::~CharacterSelect() {}

// if characters are implemented correctly

// GameState CharacterSelect::Update(float deltaTime, RenderWindow &window)
// {
//     Update (deltaTime, window, characterType);
// }

GameState CharacterSelect::Update(float deltaTime, RenderWindow &window /*,CharacterType &characterType*/)
{

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        // get mouse pos
        Vector2i mousePos = Mouse::getPosition(window);

        if(mousePos.x > 280 && mousePos.x < 490 && mousePos.y > 310 && mousePos.y < 560)
        {
             selectedCharacter = 1;
            // characterType = CharacterType::YELLOW;
            return GameState::PLAYING;
        }

        else if(mousePos.x > 540 && mousePos.x < 740 && mousePos.y > 310 && mousePos.y < 560)
        {
            selectedCharacter = 2;
            // characterType = CharacterType::RED;
            return GameState::PLAYING;
        }

        else if(mousePos.x > 790 && mousePos.x < 1280 && mousePos.y > 310 && mousePos.y < 1000)
        {
             selectedCharacter = 3;
            // characterType = CharacterType::GREEN;
            return GameState::PLAYING;

        }


    }

    return GameState::CHARACTER_SELECT; // Stay in shop if no star clicked
}


void CharacterSelect::OnActivate()
{
    playMusic();
}

void CharacterSelect::draw(RenderWindow &window)
{
    window.draw(backgroundSprite);
}

void CharacterSelect::OnExit()
{
    stopMusic();
}
int CharacterSelect::getSelectedCharacter()
{
    return selectedCharacter;
}
