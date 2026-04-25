#include"../../../include/characters/enemy/Botom.h"



    enemy_bottom::enemy_bottom(float x, float y){


        bottom_texture.loadFromFile("assets/Images/Botom_Blue.png");
        bottom_sprite.setTexture(bottom_texture);
        bottom_sprite.setTextureRect(sf::IntRect(0, 133, 120, 95));
        bottom_sprite.setPosition(x,y);
        bottom_sprite.setScale(0.6f, 0.6f);

        velocity.x = 100.0f;

        position.x=x;
        position.y=y;
                
    }

     void enemy_bottom::update_sprite_position(float delta_T){


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
                velocity.x = 100.0f;
            }

            if(position.x>1150-72)
            {
                velocity.x = -100.0f;
            }
            
            bottom_sprite.setPosition(position);

     }

         void enemy_bottom::set_Dimension(dimension_er **arr, int n)
    {
        DIMEN_ptr=arr;
        DIMEN_SIZE=n;

    }


     void enemy_bottom::draw(sf::RenderWindow &window){

        window.draw(bottom_sprite);

     }
