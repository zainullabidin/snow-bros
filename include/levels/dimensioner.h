 #pragma once
#include <SFML/Graphics.hpp>


class dimension_er{

private:

    sf::RectangleShape shape;

public:

    dimension_er(float x,float y, float w, float h );

    void draw(sf::RenderWindow& window);

     sf::FloatRect get_boundaries();


};
