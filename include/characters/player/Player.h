#pragma once

#include"../character_base.h"
#include"../HitBox.h"
#include"../../main/Input_manager.h"

#include "../../levels/dimensioner.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<iostream>
using namespace std;

class player:public character_base{

private:

    string powerUP;

    sf::Clock Power_UP_TIMER;

    bool ballon_powerup;

    bool Speed_poerup;

    bool SNOW_PU;

    bool ENCASE_POERUP;

    hitbox hi_box;

    int player_id;

    sf::Texture Player_texture;

    sf::Sprite player_sprite;

    int lives;

    input_Manager in_obj;

    dimension_er ** DIMEN_ptr;
    
    int DIMEN_SIZE;
    bool left,right;
    
    sf::Clock runner;
    int running_sprites_count;


    ///snow ball thrower
    sf::Clock throw_timer;
    bool throw_SNOWBALL;

    int snow_sprites_count;

    sf::Clock die_timer;
    bool dec;




public:

    player(){

        player_id=0;
        lives=0;
        dec=false;
        left=true,right=false;
        running_sprites_count=0;

        snow_sprites_count=0;


        ballon_powerup=false;   
        Speed_poerup=false;     
        SNOW_PU=false;          
        ENCASE_POERUP=false;    
        powerUP="NONE";         
       

        throw_SNOWBALL=false;
    }

    void set_ID(int id);

    void update_sprite_position(float delta_T)  override;

    void draw(sf::RenderWindow &) override;

    void texture_setter(int player_id);

    void set_Dimension(dimension_er ** arr, int n);

    bool left_chcker();

    bool right_chcker();

    sf::Vector2f get_positionof_player();

    void activate_SNOWBALL();

    sf::Texture& get_texture();

    hitbox& getHitbox();

     void decrease_life();

      bool is_life();

     int  get_lives();

     void reset_position(int n);

     void PowerUP_activator();

     string get_powerUP();
     
     void set_powerUP(string x);

     bool is_ballon_active();

     bool is_Speed_poerup();

     bool is_SNOW_PU();

     bool ENCASE_POERUP_GETTER();




};
