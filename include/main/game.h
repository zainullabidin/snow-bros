#pragma once
#include "Input_manager.h"
#include "../characters/projectile/Snowball.h"
#include "../characters/enemy/Botom.h"
#include"../levels/dimensioner.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include"Game_state.h"
#include "../characters/player/Player.h"
#include"Collision_detector.h"
#include "../levels/Level_Maker.h"
#include "../characters/enemy/FlyngFoogaFoog.h"




#include "../UI/GameOverScreen.h"
#include "../UI/LeaderboardScreen.h"
#include "../UI/LoginScreen.h"
#include "../UI/PauseMenuScreen.h"
#include"../UI/ShopScreen.h"


class game{

private:

 ShopScreen scrreen_SHOP_obj;


    sf::Texture SHOP;
    
    sf::Sprite Shop_sprite;


sf::Music menu_music;

sf::SoundBuffer hit;

sf::Sound Hit_sound;

sf::Music level_music;


sf::SoundBuffer THROW_BALL;


sf::Sound THROW_SOUND;

sf::SoundBuffer BOSSS_DIE;

sf::Sound DIE_SOUND;

int score_total;

sf::Text score;
sf::Text life;
sf::Text level_number;


sf::Clock level_complete_timer;


    sf::RenderWindow window;

    GameState current_state;//always importing from the enum library

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

     sf::Texture level1_bg_texture[2];
        sf::Sprite level1_bg_sprite[2];

        //now the jumping bars
        dimension_er* platforms[10];

        int platform_count;

        //bottom
        enemy_bottom** BOTTOM;
        int enemy_count;


        //snowball
        snow_ball *snowBALL_PTR;

        bool snow_checker;



        //col_detect

        Collision_DET collision_detector;

        int level;




        // screens objects 
        GameOverScreen game_over_screen;
        LeaderboardScreen leaderboard_screen;
        LoginScreen login_screen;
        PauseMenuScreen pause_menu_screen;


public:

        //ßßlevel_maker l;

        game();
        
        void update(float change_in_time);//(tam change in kitne sec)

        void display(); //all the screen shtuff goes here 

        void check_event();//updates current_state

        void run();

        void gAme_load(int level_number);

};

