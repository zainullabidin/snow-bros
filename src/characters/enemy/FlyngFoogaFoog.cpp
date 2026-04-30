#include"../../../include/characters/enemy/FlyngFoogaFoog.h"

    FF::FF(float x,float y,float speed,string path):enemy_bottom( x,  y,  speed,path){




     bottom_texture.loadFromFile("assets/Images/FlyingFoogaFoog_Orange.png");
    bottom_sprite.setTexture(bottom_texture);
    bottom_sprite.setTextureRect(sf::IntRect(0, 200, 110, 120));
    bottom_sprite.setScale(0.5f, 0.5f);

    }

    void FF::flight_mode(){

        if(!flight&&flight_time.getElapsedTime().asSeconds()>=5)//aftr every 5 sec it flies
        {
            flight=true;
            flight_time.restart();

        }
        else if(flight &&flight_time.getElapsedTime().asSeconds()>=4)
        {
            flight=false;
        }



    }

    void FF::position_getter_player(sf::Vector2f positaion_player){

        player = positaion_player;

    }

    void FF::update_sprite_position(float delta_T){


        flight_mode();

        if(get_snow_ball_counter() > 0)
            {
                enemy_bottom::update_sprite_position(delta_T);

                 bottom_sprite.setTextureRect(sf::IntRect(43, 32, 110, 150));
                return;
            }
        if(flight)
        {




            if(attacking_retreating_timer.getElapsedTime().asSeconds()>2.0f)
            {
                if(position.x < player.x) 
                position.x += 200.0f * delta_T;
              
              else 
              position.x -= 200.0f * delta_T;
        
              if(position.y < player.y) 
              position.y += 200.0f * delta_T;
       
              else
               position.y -= 200.0f * delta_T;
            }


            else
            {
                if(position.x < player.x) 
                position.x -= 200.0f * delta_T;
        
                else 
        
                position.x += 200.0f * delta_T;
       
                if(position.y < player.y) 
                
                position.y -= 200.0f * delta_T;
        
                else 
                position.y += 200.0f * delta_T;
            }
  

                
              Bottom_hitbox.hit_box_shape = sf::FloatRect(position.x, position.y, 57, 57);
              bottom_sprite.setPosition(position);

        }
        else
        {
            enemy_bottom::update_sprite_position(delta_T);
            bottom_sprite.setTextureRect(sf::IntRect(43, 32, 110, 150));
        }



    }

        void  FF::reset_flight(){

            flight=false;
            flight_time.restart();
            


        }
