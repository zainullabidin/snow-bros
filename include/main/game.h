#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include"Game_state.h"

using namespace std;

class game{

private:

    sf::RenderWindow window;

    GameState current_state;//always importing from the enum library

    bool endgame;

    sf::Font font;

    sf::Clock trailer_timer;

    sf::RectangleShape B_NewGAME;
    sf::Text txtNewGame;

    sf::RectangleShape B_LOGIN;
    sf::Text txtLogin;

    sf::RectangleShape B_Leaderboard;
    sf::Text txtLeaderboard;

    sf::RectangleShape B_Exit;
    sf::Text txtExit;

    //bg

    sf::Texture bgTexture;//for hlolding
    sf::Sprite bgSprite;//forloading

    //main mb MZ
    sf::Text MZ_Text;

    //trailer bg
    sf::Texture tariler_bg_Textture;
    sf::Sprite trailer_sprite;

    //trailer logo
    sf::Texture trailer_logo_textture;
    sf::Sprite trailer_logo_sprote;

public:

        game();
        
        void update(float change_in_time);//(tam change in kitne sec)

        void display(); //all the screen shtuff goes here 

        void check_event();//updates current_state

        void run();

};

