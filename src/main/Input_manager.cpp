#include"../../include/main/Input_manager.h"

    bool input_Manager::player_is_going_left(int player_id){

        if(player_id==1)
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            return true;
            

        }
        
        else if(player_id==2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            return true;
            

        }

        return false;


    }

    bool input_Manager::player_is_going_right(int player_id){

         if(player_id==1)
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            return true;
            

        }
        
        else if(player_id==2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            return true;
            

        }

        return false;

    }

    bool input_Manager::player_is_jumping(int player_id){

        if(player_id==1)
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            return true;
            

        }
        
        else if(player_id==2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            return true;
            

        }

        return false;

    }

    bool input_Manager::player_is_throwing(int player_id){

        if(player_id==1)
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            return true;
            

        }
        
        else if(player_id==2)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            return true;
            

        }

        return false;

    }

    bool input_Manager::player_is_pausing(int player_id){

          if(player_id==1||player_id==2)
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            return true;
            

        }

        return false;
    }

    bool input_Manager::player_HITBOX(int player_id){


        if(player_id==1||player_id==2)
        {
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
            return true;
            

        }

        return false;

        
    }

    //so in summary these are the keys
    // Playwer 01.   right->D left-?A jump->W throw->S 
    //Playwer 02.   right->arrow -right 
    //left- arrow  left
    //jump->arrow up
    // throw ->     throw->arrow down
    //.   

    //      common keys
    // TOGGLE HITBOx =T
    // Pause the game =P
    //