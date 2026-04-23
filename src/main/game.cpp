#include"../../include/main/game.h"


 
        game::game(){

            window.create(sf::VideoMode(800, 600), "SNOW BROS-By MZ");//screens saz and apna mark


            //title font
            font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf");

            titleText.setFont(font);

            titleText.setString("SNOW BROS");

            titleText.setCharacterSize(48);

            titleText.setFillColor(sf::Color::White);

            titleText.setPosition(200, 250);
            
            current_state=GameState::TRAILER;

            //clcik button-1
            B_NewGAME.setSize(sf::Vector2f(300, 50));
            B_NewGAME.setPosition(250, 200);
            B_NewGAME.setFillColor(sf::Color(50, 50, 200));
            txtNewGame.setFont(font);
            txtNewGame.setString("NEW GAME");
            txtNewGame.setCharacterSize(20);
            txtNewGame.setPosition(270, 215);

            //btn-2
            B_LOGIN.setSize(sf::Vector2f(300, 50));
            B_LOGIN.setPosition(250, 280);
            B_LOGIN.setFillColor(sf::Color(50, 50, 200));
            txtLogin.setFont(font);
            txtLogin.setString("LOGIN");
            txtLogin.setCharacterSize(20);
            txtLogin.setPosition(270, 295);

            //bten-3
            B_Leaderboard.setSize(sf::Vector2f(300,50));
            B_Leaderboard.setPosition(250,360);
            B_Leaderboard.setFillColor(sf::Color(50, 50, 200));
            txtLeaderboard.setFont(font);
            txtLeaderboard.setString("LEADERBOARD");
            txtLeaderboard.setPosition(270, 375);

            //btn-4
            B_Exit.setSize(sf::Vector2f(300,50));
            B_Exit.setPosition(250,440);
            B_Exit.setFillColor(sf::Color(50, 50, 200));
            txtExit.setFont(font);
            txtExit.setString("EXIT");
            txtExit.setPosition(270, 455);






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
            if(current_state == GameState::MAIN_MENU){
                if (current_state == GameState::MAIN_MENU) {

                    window.draw(B_NewGAME);
                    window.draw(txtNewGame);
                    window.draw(B_LOGIN);
                    window.draw(txtLogin);
                    window.draw(B_Leaderboard);
                    window.draw(txtLeaderboard);
                    window.draw(B_Exit);
                    window.draw(txtExit);
                }
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
                if(event.type==sf::Event::MouseButtonPressed){
                    if(event.mouseButton.button==sf::Mouse::Left)
                    {
                        sf::Vector2f mouse_click_position(event.mouseButton.x,event.mouseButton.y);
                        //now checkinh again each button
                        if(B_NewGAME.getGlobalBounds().contains(mouse_click_position))
                        current_state=GameState::PLAYING;
                        if(B_LOGIN.getGlobalBounds().contains(mouse_click_position))
                        current_state=GameState::LOGIN;
                        if(B_Leaderboard.getGlobalBounds().contains(mouse_click_position))
                        current_state=GameState::LEADERBOARD;
                        if(B_Exit.getGlobalBounds().contains(mouse_click_position))
                        window.close();
                    }
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
