#pragma once
#include"../character_base.h"
#include <SFML/Graphics.hpp>


class snow_ball:public character_base{

private:

    sf::Texture ball_texture;
    sf::Sprite ball_sprite;

    bool checker;

    bool Direction_left;

public:

    snow_ball(float x, float y, bool check);

    void update_sprite_position(float delta_T)override;

    void draw(sf::RenderWindow &window)override;

    bool snowbal_checker();

    void ball_vanisher();
};
