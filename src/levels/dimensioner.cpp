#include"../../include/levels/dimensioner.h"


   dimension_er:: dimension_er(float x,float y, float w, float h ){

     shape.setSize(sf::Vector2f(w, h));
     shape.setPosition(x, y);
     shape.setFillColor(sf::Color(255, 0, 0, 180));//got. these  n numbers from AI



   }

    void dimension_er::draw(sf::RenderWindow& window){

        window.draw(shape);

    }

     sf::FloatRect dimension_er::get_boundaries(){

        return shape.getGlobalBounds();
     }

