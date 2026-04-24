#include"../../include/main/Collision_detector.h"



bool Collision_DET::MAIN_OVERLAP_DETECTOR(sf::FloatRect &f1,sf::FloatRect &f2)
{
    return false;
}
bool Collision_DET::player_HitsEnemy(hitbox &Player_box, hitbox &Enemy_box)
{
    return false;
}
bool Collision_DET::snowball_HitsEnemy(hitbox &snow_ball_box, hitbox &Enemy_box)
{
    return false;
}
bool Collision_DET::projectile_HitsPlayer(hitbox &projectile_box, hitbox &Player_box)
{
    return false;
}
bool Collision_DET::sprite_On_Bars(hitbox &Sprite_box,hitbox &Bar_box )
{
    return false;
}
bool Collision_DET::rollingSnowball_HitsEnemy(hitbox &Snowball_rolling_box ,hitbox &Enemy_box)
{
    return false;
}
bool Collision_DET::OnGround_checker(hitbox &Sprite_box, hitbox &Ground_box)
{
    return false;
}