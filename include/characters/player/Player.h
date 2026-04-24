#pragma once

#include"../character_base.h"
#include"../HitBox.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class player:public character_base{

private:

    hitbox hi_box;

    int player_id;

    sf::Texture Player_texture;

    sf::Sprite player_sprite;

    int lives;

public:

    player(){
        player_id=0;
        lives=0;
    }

    void set_ID(int id);

    void update_sprite_position(float delta_T) override;

    void draw(sf::RenderWindow &) override;




};