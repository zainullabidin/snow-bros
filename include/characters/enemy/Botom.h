#pragma once
#include<SFML/Graphics.hpp>
#include"../HitBox.h"
#include"../character_base.h"
#include "../../levels/dimensioner.h"
#include <SFML/Window.hpp>


class enemy_bottom:public character_base{

private:


    hitbox Bottom_hitbox;

    float speed;

    sf::Texture bottom_texture;

    sf::Sprite bottom_sprite;

    dimension_er ** DIMEN_ptr;
    
    int DIMEN_SIZE;

public:

    enemy_bottom(float x, float y);

     void update_sprite_position(float delta_T)  override;

     void draw(sf::RenderWindow &) override;


    void set_Dimension(dimension_er ** arr, int n);
}; 