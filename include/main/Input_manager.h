#pragma once

#include<SFML/Window.hpp>

class input_Manager{

public:
    bool player_is_going_left(int player_id);

     bool player_is_going_right(int player_id);

     bool player_is_jumping(int player_id);

    bool player_is_throwing(int player_id);

     bool player_is_pausing(int player_id);

      bool player_HITBOX(int player_id);

};