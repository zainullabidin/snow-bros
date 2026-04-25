#include"../../../include/characters/projectile/Snowball.h"


    snow_ball::snow_ball(float x, float y, bool check){

        ball_texture.loadFromFile("assets/Images/Nick.png");
        ball_sprite.setTexture(ball_texture);
        ball_sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));//shhet cords
        ball_sprite.setPosition(x,y);
        ball_sprite.setScale(0.3f,0.3f);//dummy scale scale ios basiclayy the size
        position.x=x;
        position.y=y;
        checker=check;
        Direction_left=check;
    }

    void snow_ball::update_sprite_position(float delta_T){

    }

    void snow_ball::draw(sf::RenderWindow & window){

        window.draw(ball_sprite);

    }

    bool snow_ball::snowbal_checker(){


        return checker;

    }
    
    void snow_ball::ball_vanisher(){

    }