#include"../../include/main/game.h"


 
        game::game(){

            window.create(sf::VideoMode(800, 600), "SNOW BROS-By MZ");

            font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf");

            titleText.setFont(font);

            titleText.setString("SNOW BROS");

            titleText.setCharacterSize(48);

            titleText.setFillColor(sf::Color::White);

            titleText.setPosition(200, 250);
            
            current_state=GameState::TRAILER;

            if (!font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf")) {
    window.close();
    return;
}
        }
        
        void game::update(float change_in_time){

        
            if (current_state == GameState::TRAILER) {
   
                if (trailer_timer.getElapsedTime().asSeconds() >= 3.0f) {
    
                    current_state = GameState::MAIN_MENU;
   
                }

            }
        }//(tam change in kitne sec)

        void game::display(){
    
            window.clear(sf::Color::Black);
    
  
            if (current_state == GameState::TRAILER) {
   
    
                window.draw(titleText);
  
            }
    
   
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
