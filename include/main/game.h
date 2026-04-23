#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include"Game_state.h"

using namespace std;

class game{

private:

    sf::RenderWindow window;

    string current_state;//always importing from the enum library

    bool endgame;

public:

        game();
        
        void update(float change_in_time);//(tam change in kitne sec)

        void display(); //all the screen shtuff goes here 

        void check_event();//updates current_state

        void run();

};

