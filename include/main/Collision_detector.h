#pragma once
#include <SFML/Graphics.hpp>

#include "../characters/HitBox.h"

class Collision_DET{

    public:


    bool MAIN_OVERLAP_DETECTOR(sf::FloatRect &f1,sf::FloatRect &f2);
    bool player_HitsEnemy(hitbox &Player_box, hitbox &Enemy_box);
    bool snowball_HitsEnemy(hitbox &snow_ball_box, hitbox &Enemy_box);
    bool projectile_HitsPlayer(hitbox &projectile_box, hitbox &Player_box);
    bool sprite_On_Bars(hitbox &Sprite_box,hitbox &Bar_box );
    bool rollingSnowball_HitsEnemy(hitbox &Snowball_rolling_box ,hitbox &Enemy_box);
    bool OnGround_checker(hitbox &Sprite_box, hitbox &Ground_box);
};
