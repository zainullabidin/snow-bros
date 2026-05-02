 #include"../../include/main/Collision_detector.h"



bool Collision_DET::MAIN_OVERLAP_DETECTOR(sf::FloatRect &f1,sf::FloatRect &f2)
{
    if(f1.intersects(f2))
    return true;

    return false;
}
bool Collision_DET::player_HitsEnemy(hitbox &Player_box, hitbox &Enemy_box)
{
    if(MAIN_OVERLAP_DETECTOR(Player_box.hit_box_shape,Enemy_box.hit_box_shape))
    return true;

    return false;
}
bool Collision_DET::snowball_HitsEnemy(hitbox &snow_ball_box, hitbox &Enemy_box)
{
    if(MAIN_OVERLAP_DETECTOR(snow_ball_box.hit_box_shape,Enemy_box.hit_box_shape))
    return true;

    return false;

}
bool Collision_DET::projectile_HitsEnemy(hitbox &projectile_box, hitbox &Player_box)
{
    if(MAIN_OVERLAP_DETECTOR(projectile_box.hit_box_shape,Player_box.hit_box_shape))
    return true;

    return false;
}
bool Collision_DET::sprite_On_Bars(hitbox &Sprite_box,hitbox &Bar_box )
{
    return false;
}
bool Collision_DET::rollingSnowball_HitsEnemy(hitbox &Snowball_rolling_box ,hitbox &Enemy_box)
{

     if(MAIN_OVERLAP_DETECTOR(Snowball_rolling_box.hit_box_shape,Enemy_box.hit_box_shape))
    return true;


    return false;
}
bool Collision_DET::OnGround_checker(hitbox &Sprite_box, hitbox &Ground_box)
{
    return false;
}