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
    
    sf::Text titleText;

    sf::Clock trailer_timer;

    sf::RectangleShape B_NewGAME;
    sf::Text txtNewGame;

    sf::RectangleShape B_LOGIN;
    sf::Text txtLogin;

    sf::RectangleShape B_Leaderboard;
    sf::Text txtLeaderboard;

    sf::RectangleShape B_Exit;
    sf::Text txtExit;

public:

        game();
        
        void update(float change_in_time);//(tam change in kitne sec)

        void display(); //all the screen shtuff goes here 

        void check_event();//updates current_state

        void run();

};

