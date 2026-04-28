#pragma once
#include<SFML/Graphics.hpp>
#include"../HitBox.h"
#include"../character_base.h"
#include "../../levels/dimensioner.h"
#include <SFML/Window.hpp>


class enemy_bottom:public character_base{

private:


    hitbox Bottom_hitbox;

    sf::Texture bottom_texture;

    sf::Sprite bottom_sprite;

    dimension_er ** DIMEN_ptr;
    
    int DIMEN_SIZE;

    sf::Clock walker_bottom;
    int walkingsprite;

    bool left,right;

    int snow_ball_counter;

    sf::Clock  ball_break_timer;

    sf::Texture *ball_casing;
    sf::Sprite anow_ball_casing;


    bool alive;

    bool roll;



public:
    enemy_bottom():enemy_bottom(0,0){}
    

    enemy_bottom(float x, float y);

     void update_sprite_position(float delta_T)  override;

     void draw(sf::RenderWindow &) override;

    void set_Dimension(dimension_er ** arr, int n);

    hitbox& getHIT_box();

    void get_hit();

    int get_snow_ball_counter() const;

    void set_nick_texture(sf::Texture &ptr);

    bool check_alive();

    void set_rooling(bool nick_face_side);

    bool get_rooling();

    void set_dead();



}; 