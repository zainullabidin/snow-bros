#pragma once
#include <SFML/Graphics.hpp>

class character_base {

protected:

    sf::Vector2f position;
    sf::Vector2f velocity;
    bool alive;
public:

    virtual void update_sprite_position(float delta_T) =0;

    virtual void draw(sf::RenderWindow &) = 0;

    virtual ~ character_base(){}

};
