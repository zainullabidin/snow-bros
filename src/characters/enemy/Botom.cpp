#include"../../../include/characters/enemy/Botom.h"



    enemy_bottom::enemy_bottom(float x, float y){


        alive=true;
        roll=false;

        left=false,right=true;
        bottom_texture.loadFromFile("assets/Images/Botom_Blue.png");
        bottom_sprite.setTexture(bottom_texture);
        bottom_sprite.setTextureRect(sf::IntRect(0, 133, 120, 95));
        bottom_sprite.setPosition(x,y);
        bottom_sprite.setScale(0.6f, 0.6f);

        velocity.x = 100.0f;

        position.x=x;
        position.y=y;

        walkingsprite=0;
        snow_ball_counter=0;
                
    }

     void enemy_bottom::update_sprite_position(float delta_T){

        if(snow_ball_counter==0&&velocity.x==0)
        {
            if(right)
            {
                velocity.x=100.0f;
            }
            else
            velocity.x=-100.0f;
        }

            

             velocity.y += 500.0f * delta_T;
             position.x += velocity.x * delta_T;  
             position.y += velocity.y * delta_T;


             for(int i=0;i<DIMEN_SIZE;i++)
            {
                sf::FloatRect pos=DIMEN_ptr[i]->get_boundaries();

                float bottom_BOTTOM=position.y+57;

                float center_x = position.x + 36;

                if(bottom_BOTTOM>=pos.top&&bottom_BOTTOM<=pos.top+15&&center_x>pos.left&&center_x<pos.left+pos.width&&velocity.y>0)
                {
                    position.y = pos.top - 57;
                    velocity.y=0;
                }
            }




            if(position.x<130)
            {
                position.x=130;

                    if(roll)
                    {
                        set_dead();
                    }

                if(snow_ball_counter == 0)
                {
                 velocity.x = 100.0f;
                left=false,right=true;

                }
                
            }

            if(position.x>1150-72)
            {
                position.x = 1150-72;
                    if(roll)
                   set_dead();
                if(snow_ball_counter == 0)
                {
                    velocity.x = -100.0f;
                   left=true,right=false;
                }
                
            }

             if(walker_bottom.getElapsedTime().asSeconds()>0.3f)
            {
                walkingsprite=0;
            }

                if(walker_bottom.getElapsedTime().asSeconds()>0.15f)
                {
                    walkingsprite=(walkingsprite%2)+1;
                    walker_bottom.restart();
                }
                
            
             int x=walkingsprite*94;
             if(right)
                
                bottom_sprite.setTextureRect(sf::IntRect(x+94, 366, -94, 88));
             else
                bottom_sprite.setTextureRect(sf::IntRect(x, 366, 94, 88));


        if(snow_ball_counter>=1)
        {

             bottom_sprite.setTextureRect(sf::IntRect(0, 712, 98, 86));
        }
        
        if(ball_break_timer.getElapsedTime().asSeconds()>4&&snow_ball_counter>=1)
        {

            snow_ball_counter--;
            ball_break_timer.restart();

        }




            
            
            bottom_sprite.setPosition(position);
            Bottom_hitbox.hit_box_shape=sf::FloatRect(position.x,position.y,57,57);

     }

         void enemy_bottom::set_Dimension(dimension_er **arr, int n)
    {
        DIMEN_ptr=arr;
        DIMEN_SIZE=n;

    }


     void enemy_bottom::draw(sf::RenderWindow &window){

     
        window.draw(bottom_sprite);
        if(snow_ball_counter==1)
        {
            anow_ball_casing.setTextureRect(sf::IntRect(90, 3281, 297, 302));
        }
        else if(snow_ball_counter==2)
        {
            anow_ball_casing.setTextureRect(sf::IntRect(387, 3281, 297, 302));
        }
        else if(snow_ball_counter==3)
        {
            anow_ball_casing.setTextureRect(sf::IntRect(684, 3281, 297, 302));
        }
        else if(snow_ball_counter==4)
        {
            anow_ball_casing.setTextureRect(sf::IntRect(981, 3281, 297, 302));
        }

        anow_ball_casing.setPosition(position.x - 18, position.y - 18);

        if(snow_ball_counter)

        window.draw(anow_ball_casing);

     }


    hitbox& enemy_bottom::getHIT_box(){
        return Bottom_hitbox;
    }

    void enemy_bottom::get_hit()
    {
            if(snow_ball_counter<=5)
            snow_ball_counter++;
            else
            snow_ball_counter=5;
            ball_break_timer.restart();

            velocity.y = 0.0f;

            velocity.x = 0.0f;

    }


    int enemy_bottom::get_snow_ball_counter() const{

        return snow_ball_counter;


    }

    void enemy_bottom::set_nick_texture(sf::Texture &ptr){

        if(ball_casing==NULL)
        {
            ball_casing=new sf::Texture;
        }
        else
        ball_casing=NULL;

        ball_casing=&ptr;
        anow_ball_casing.setTexture(*ball_casing);
        anow_ball_casing.setScale(0.3f, 0.3f);

    }

     bool enemy_bottom::check_alive(){
        return alive;
     }

     void enemy_bottom::set_dead(){
        alive=false;
     }

     void enemy_bottom::set_rooling(bool nick_face_side){

             if(nick_face_side)///basicalyy right side
                velocity.x=-400.0f;
                    else
               velocity.x=400.0f;

              roll=true;
     }

     void enemy_bottom::remove_rooling(){

        roll=false;
     }

     bool enemy_bottom::get_rooling(){


        return roll;
     }
