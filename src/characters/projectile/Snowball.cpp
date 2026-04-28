#include"../../../include/characters/projectile/Snowball.h"


    snow_ball::snow_ball(float x, float y, bool check){


        ball_sprite.setRadius(10);


        ball_sprite.setFillColor(sf::Color::White);
        ball_sprite.setPosition(x, y);//dummy scale scale ios basiclayy the size
        position.x=x;
        position.y=y;
        checker=true;
        Direction_left=check;

    }

    void snow_ball::update_sprite_position(float delta_T){

        if(checker==false)
        {
            return;
        }

        if(Direction_left)
        {
             position.x-=500.0f*delta_T;
        }
        else{
            position.x+=500.0f*delta_T;
        }

        if(position.x<130||position.x>1150)//walls
        checker=false;

        ball_sprite.setPosition(position);
        snow_ball_Hitbox.hit_box_shape=sf::FloatRect(position.x,position.y,20,20);


    }

    void snow_ball::draw(sf::RenderWindow & window){

        window.draw(ball_sprite);

    }

    bool snow_ball::snowbal_checker(){

         return checker;

    }
    
    void snow_ball::ball_vanisher(){
        checker=false;
    }

        hitbox& snow_ball::getHit_box(){
        return  snow_ball_Hitbox;
    }