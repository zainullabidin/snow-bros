#include"../../../include/characters/player/Player.h"

    void player::update_sprite_position(float delta_T) {//movemenys

       if(in_obj.player_is_going_left(player_id))
       {
           position.x-= 200.0f * delta_T;
            right=false;
            left=true;
 
       }
       if(in_obj.player_is_going_right(player_id))
       {
            position.x+= 200.0f * delta_T;
            left=false;
            right=true;

       }
       if(in_obj.player_is_jumping(player_id)&&velocity.y==0)
       {
             velocity.y=-350.0f;
       }




        if(throw_SNOWBALL)
       {

        if(throw_timer.getElapsedTime().asSeconds()>0.1f)
        {
            throw_SNOWBALL=false;
            
        }
        else
        {
            if(throw_timer.getElapsedTime().asSeconds()>0.05f)
            {
                snow_sprites_count=(snow_sprites_count+1)%2;
                
                
            }
               int x=409+snow_sprites_count*257;
            if(right)
                
                player_sprite.setTextureRect(sf::IntRect(x + 220, 1580, -257, 310));
            else
                player_sprite.setTextureRect(sf::IntRect(x, 1580, 257, 310));
        }

       }


       

      else  if(in_obj.player_is_going_left(player_id)||in_obj.player_is_going_right(player_id))
       {
        int width_proceeder=0;

            if(runner.getElapsedTime().asSeconds()>0.15f)
            {
                running_sprites_count=((running_sprites_count)%3)+1;
                runner.restart ();
            }

                 width_proceeder=running_sprites_count*328;

                 if(right)
            player_sprite.setTextureRect(sf::IntRect(width_proceeder+322, 0, -322, 350));

        else if(left)
            
            player_sprite.setTextureRect(sf::IntRect(width_proceeder, 0, 322, 350));


       }
       else
       {
        if(right)
            player_sprite.setTextureRect(sf::IntRect(322, 0, -322, 350));

            else if(left)
            
            player_sprite.setTextureRect(sf::IntRect(0, 0, 322, 350));

       }

       


        

       


  



       //gravity acting
            velocity.y += 500.0f * delta_T;
             position.y += velocity.y * delta_T;
           
     for(int i=0;i<DIMEN_SIZE;i++)
     {
        sf::FloatRect pos=DIMEN_ptr[i]->get_boundaries();

              float nick_left = position.x;
             float nick_right = position.x + 77;
             float bottom_nick = position.y + 105;
  
        if(bottom_nick>=pos.top&&bottom_nick<=pos.top+15&&nick_right>pos.left&&nick_left<pos.left+pos.width&&velocity.y>0)
        {
             position.y = pos.top - 100;
             velocity.y=0;
        }

     }

      

       //boundary checks for screen 

       if(position.x<130)
       {
          position.x=130;
       }
       if(position.y<0)
       {
          position.y=0;
       }

       if(position.x>1150-77)
       {
         position.x=1073;
       }
       if(position.y+90>680)
       {
          position.y=590;
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
        
        }
    }

    void player::set_Dimension(dimension_er **arr, int n)
    {
        DIMEN_ptr=arr;
        DIMEN_SIZE=n;

    }

    bool player::left_chcker(){

        return left;

    }

    bool player::right_chcker(){

        return right;
    }

    sf::Vector2f player::get_positionof_player(){
        return position;
    }

    void player::activate_SNOWBALL(){
        
        throw_SNOWBALL=true;

        throw_timer.restart();

    }