#pragma once
#include"Botom.h"
#include<string>


class FF:public enemy_bottom{

private:


    sf::Clock flight_time;

    sf::Clock ground_time;

    sf::Clock attacking_retreating_timer;

    sf::Vector2f player;

    bool flight;



public:

    FF(float x,float y,float speed,string path);

    void flight_mode();

        void position_getter_player(sf::Vector2f positaion_player);

        void update_sprite_position(float delta_T)override;

        void reset_flight();


};
