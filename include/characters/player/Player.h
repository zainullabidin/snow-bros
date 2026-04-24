#pragma once

#include"../character_base.h"
#include"../HitBox.h"
#include"../../main/Input_manager.h"

#include "../../levels/dimensioner.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class player:public character_base{

private:

    hitbox hi_box;

    int player_id;

    sf::Texture Player_texture;

    sf::Sprite player_sprite;

    int lives;

    input_Manager in_obj;

    dimension_er ** DIMEN_ptr;
    int DIMEN_SIZE;


public:

    player(){
        player_id=0;
        lives=0;
    }

    void set_ID(int id);

    void update_sprite_position(float delta_T)  override;

    void draw(sf::RenderWindow &) override;

    void texture_setter(int player_id);

    void set_Dimension(dimension_er ** arr, int n);



};