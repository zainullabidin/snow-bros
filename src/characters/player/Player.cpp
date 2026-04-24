#include"../../../include/characters/player/Player.h"

    void player::update_sprite_position(float delta_T) {

       if(in_obj.player_is_going_left(player_id))
       {
           position.x-= 200.0f * delta_T;
       }
       if(in_obj.player_is_going_right(player_id))
       {
            position.x+= 200.0f * delta_T;
       }
       if(in_obj.player_is_jumping(player_id)&&position.y>=620)
       {
             velocity.y=-450.0f;
       }

       //gravity acting
            velocity.y += 500.0f * delta_T;
             position.y += velocity.y * delta_T;
           


      

       //boundary checks for screen 

       if(position.x<0)
       {
          position.x=0;
       }
       if(position.y<0)
       {
          position.y=0;
       }

       if(position.x>1280-90)
       {
         position.x=1190;
       }
       if(position.y>720-90)
       {
          position.y=630;
          velocity.y = 0;
       }


        player_sprite.setPosition(position);



    }

    void player::draw(sf::RenderWindow &window) {

        window.draw(player_sprite);

    }


    void player::set_ID(int id){

        player_id=id;
        lives=3;

        texture_setter(player_id);
        
    }

    void player::texture_setter(int player_id){
        if(player_id==1)
        {
            Player_texture.loadFromFile("assets/Images/Nick.png");
            player_sprite.setTexture(Player_texture);
            player_sprite.setTextureRect(sf::IntRect(0, 0, 322, 350));//got these numbers with the help of AI
            player_sprite.setPosition(100, 500);
            player_sprite.setScale(0.3f, 0.3f);
            
            position.x = 100;
            position.y = 500;
        }
    }


