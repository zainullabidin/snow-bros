#pragma once
#include "Input_manager.h"
#include"../levels/dimensioner.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include"Game_state.h"
#include "../characters/player/Player.h"

using namespace std;

class game{

private:

    sf::RenderWindow window;

    GameState current_state;//always importing from the enum library

    bool endgame;

    sf::Font font;

    sf::Clock trailer_timer;


    sf::Text txtNewGame;


    sf::Text txtLogin;


    sf::Text txtLeaderboard;


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

    //main mwnu frames 
    sf::Texture B_Frame_texture;
    sf::Texture B_NewGameTexture;

    //sprites for each button
    sf::Sprite B_NewGameSprite;
    sf::Sprite B_LoginSprite;
    sf::Sprite B_LeaderboardSprite;
    sf::Sprite B_ExitSprite;

    //
    input_Manager obj_for_input;

    //plsyers
    
     player player1;
     player player2;


     sf::Clock game_timer;

     //level1

     sf::Texture level1_bg_texture;
        sf::Sprite level1_bg_sprite;

        //now the jumping bars
        dimension_er* platforms[10];

        int platform_count;


public:

        game();
        
        void update(float change_in_time);//(tam change in kitne sec)

        void display(); //all the screen shtuff goes here 

        void check_event();//updates current_state

        void run();

};

