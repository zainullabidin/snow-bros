#include"../../include/main/game.h"


 
        game::game(){

            window.create(sf::VideoMode(800, 600), "SNOW BROS-By MZ");
        }
        
        void game::update(float change_in_time){

            //idk how to do this

        }//(tam change in kitne sec)

        void game::display(){
           
            window.clear(sf::Color::Blue);
    
            window.display();

        } //all the screen shtuff goes here 

        void game::check_event(){

            sf::Event event;
            
            while (window.pollEvent(event)) {
       
                if (event.type == sf::Event::Closed) {
         
                    window.close();
       
                }
       
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            
                    window.close();
        
                }
  
            }

        }//updates current_state

        void game::run() {
        
            while (window.isOpen()) {
       
                check_event();
       
                update(0.0f);
       
                display();
    }
}
