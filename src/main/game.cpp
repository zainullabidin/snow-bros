#include"../../include/main/game.h"
#include "../../include/UI/LeaderboardScreen.h"
#include<iostream>

 //2 places
        game::game(){

            logged_In_User="";
            score_saved=false;
            coins = 0;

            SHOP.loadFromFile("assets/Images/shopicon.png");
            Shop_sprite.setTexture(SHOP);
            Shop_sprite.setScale(97.0f / SHOP.getSize().x, 97.0f / SHOP.getSize().y);
            Shop_sprite.setPosition(1150, 10);


            THROW_BALL.loadFromFile("assets/Sounds/throw.wav");
            THROW_SOUND.setBuffer(THROW_BALL);
            BOSSS_DIE.loadFromFile("assets/Sounds/die_BOSS.wav");
            DIE_SOUND.setBuffer(BOSSS_DIE);

            hit.loadFromFile("assets/Sounds/hit.wav");
            Hit_sound.setBuffer(hit);

            menu_music.openFromFile("assets/Sounds/snow_bros_theme_01.ogg");
            menu_music.setLoop(true);
            menu_music.play();

            level_music.openFromFile("assets/Sounds/snow_bros_level.ogg");
            level_music.setLoop(true);



            font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf");
            score_total=0;


             score.setFont(font);
             score.setCharacterSize(20);
             score.setFillColor(sf::Color::Yellow);

             score.setPosition(20, 20);


            life.setFont(font);
             life.setCharacterSize(20);
             life.setFillColor(sf::Color::Yellow);

             life.setPosition(20, 50);

            level_number.setFont(font);
             level_number.setCharacterSize(20);
             level_number.setFillColor(sf::Color::Yellow);

             level_number.setPosition(20, 80);


             level1_bg_texture[0].loadFromFile("assets/Images/level1.png");
            level1_bg_texture[1].loadFromFile("assets/Images/level2.png");

            level1_bg_sprite[0].setTexture(level1_bg_texture[0]);
            level1_bg_sprite[1].setTexture(level1_bg_texture[1]);

            level1_bg_sprite[0].setScale(1280.0f / level1_bg_texture[0].getSize().x, 720.0f / level1_bg_texture[0].getSize().y);
            level1_bg_sprite[1].setScale(1280.0f / level1_bg_texture[1].getSize().x, 720.0f / level1_bg_texture[1].getSize().y);


            // for(int i=0;i<10;i++)
            // {
            //     string bg_name;
            //     bg_name="assets/Images/level"+to_string(i+1)+ ".png";
            //     level1_bg_texture[i].loadFromFile(bg_name);
            //     level1_bg_sprite[i].setTexture(level1_bg_texture[i]);
            //     level1_bg_sprite[i].setScale(1280.0f / level1_bg_texture[i].getSize().x, 720.0f / level1_bg_texture[i].getSize().y);


            // }

            BOTTOM = NULL;
            level=0;
            enemy_count = 0;
            snowBALL_PTR=NULL;
            snow_checker=false;
            score_saved=false;
    

            
            window.create(sf::VideoMode(1280, 720), "SNOW BROS-By MZ");//screens saz and apna mark
            //maim menu content loacer
            B_Frame_texture.loadFromFile("assets/images/frame.png");
            B_NewGameTexture.loadFromFile("assets/images/frame_snowbro.png");

            float B_NewGame_Scale_X = 420.0f / 818.0f;
            float B_NewGame_Scale_Y = 110.0f / 305.0f;
            B_NewGameSprite.setScale(B_NewGame_Scale_X, B_NewGame_Scale_Y);
            B_NewGameSprite.setTexture(B_NewGameTexture);
            B_NewGameSprite.setPosition(280, 195);
            txtNewGame.setPosition(420, 237);

            float B_Scale_X = 380.0f / 1234.0f;
            float B_Scale_Y = 80.0f / 202.0f;


            //adding sprites for main menu 



            B_LoginSprite.setTexture(B_Frame_texture);
            B_LoginSprite.setScale(B_Scale_X, B_Scale_Y);
            B_LoginSprite.setPosition(300, 320);


            B_LeaderboardSprite.setTexture(B_Frame_texture);
            B_LeaderboardSprite.setScale(B_Scale_X, B_Scale_Y);
            B_LeaderboardSprite.setPosition(300, 420);


            B_ExitSprite.setTexture(B_Frame_texture);
            B_ExitSprite.setScale(B_Scale_X, B_Scale_Y);
            B_ExitSprite.setPosition(300, 520);

            //logo
            trailer_logo_textture.loadFromFile("assets/images/title+logo.png");
            trailer_logo_sprote.setTexture(trailer_logo_textture);
            trailer_logo_sprote.setScale(0.8f, 0.8f);
            trailer_logo_sprote.setPosition(300, 150);


            tariler_bg_Textture.loadFromFile("assets/images/trailer_bg.png");
            trailer_sprite.setTexture(tariler_bg_Textture);
            trailer_sprite.setScale(1280.0f / tariler_bg_Textture.getSize().x,720.0f / tariler_bg_Textture.getSize().y
);
            //bg load
            bgTexture.loadFromFile("assets/images/background.png");


            
            current_state=GameState::TRAILER;

            //clcik button-1


            txtNewGame.setFont(font);
            txtNewGame.setString("NEW GAME");
            txtNewGame.setCharacterSize(22);
   

            //btn-2

            txtLogin.setFont(font);
            txtLogin.setString("LOGIN");
            txtLogin.setCharacterSize(22);
            txtLogin.setPosition(430, 345);

            //bten-3

            txtLeaderboard.setFont(font);
            txtLeaderboard.setCharacterSize(22);
            txtLeaderboard.setString("LEADERBOARD");
            txtLeaderboard.setPosition(390, 445);

            //btn-4

            txtExit.setFont(font);
            txtExit.setString("EXIT");
            txtExit.setCharacterSize(22);
            txtExit.setPosition(430, 545);

            bgSprite.setTexture(bgTexture);
            //scaling acc to size
            bgSprite.setScale(1280.0f / bgTexture.getSize().x,720.0f / bgTexture.getSize().y);


            MZ_Text.setFont(font);
            MZ_Text.setString("Made by Minahil & Zain");
            MZ_Text.setCharacterSize(16);
            MZ_Text.setFillColor(sf::Color(10, 10, 80));
            MZ_Text.setPosition(400, 500);


             player1.set_ID(1);
             
             player2.set_ID(2);



             //the jumping bars thingy&

             ///each bar dimensions

             platform_count = 7;

            platforms[0] = new dimension_er(130, 693, 1020, 30);  // ground
            platforms[1] = new dimension_er(135, 580, 230, 30);   //brtonm left one
            platforms[2] = new dimension_er(920, 580, 230, 30);  // right_(BOTTOM)
            platforms[3] = new dimension_er(320, 475, 640, 30);   //  THE CENTER ONE
            platforms[4] = new dimension_er(130, 370, 425, 30); // up -left opne
            platforms[5] = new dimension_er(720, 370, 425, 30); ///up_right one
            platforms[6] = new dimension_er(525, 585, 245, 30);  //bootom middle
            player1.set_Dimension(platforms,platform_count);
            player2.set_Dimension(platforms,platform_count);

            //bottom

            gAme_load(level);


        }
 
        //MULTIPLE PLACES
        void game::update(float change_in_time){

        
            if (current_state == GameState::TRAILER) {
   
                if (trailer_timer.getElapsedTime().asSeconds() >= 3.5f) {
    
                    current_state = GameState::MAIN_MENU;
   
                }

            }

            if(current_state==GameState::REGISTER)
            {
                    login_screen.setMode(GameState::REGISTER);
                    current_state = login_screen.Update(change_in_time, window);
                    if(current_state == GameState::PLAYING || current_state == GameState::CHARACTER_SELECT)
                    {
                        logged_In_User = login_screen.getLoggedInUsername();
                    }
            }

            if(current_state == GameState::CHARACTER_SELECT)
            {
                current_state = character_screen.Update(change_in_time, window);
            }

            if(current_state==GameState::PLAYING)
            {

                if(level_music.getStatus() != sf::Music::Playing)
                    {
                        menu_music.stop();
                        level_music.play();
                    }


                   

                if(player1.is_life())   
                player1.update_sprite_position(change_in_time);
                player1.PowerUP_activator();
                 if(player2.is_life())
                player2.update_sprite_position(change_in_time);
                player2.PowerUP_activator();

                //bonus levels
                if( arr_main_levels[level].bonus)
                {
                     current_state=GameState::STAR_EVENT;
                     return;
                }
                  


                for(int I=0;I<enemy_count;I++)
                {
                    {
                        if(BOTTOM[I]->check_alive())
                        {
                            FF* flying_ff=dynamic_cast<FF*>(BOTTOM[I]);
                            if(flying_ff!=NULL)
                            {
                                static int x=0;
                                if(x%2==0&&player1.is_life())
                                flying_ff->position_getter_player(player1.get_positionof_player());
                                else if(x%2==1&&player2.is_life())
                                flying_ff->position_getter_player(player2.get_positionof_player());
                            }
                                BOTTOM[I]->update_sprite_position(change_in_time);;

                            


                                
                            
                        }
                        
                    }
                }

            
                if(!(snowBALL_PTR==NULL)&&snow_checker)
            {
                snowBALL_PTR->update_sprite_position(change_in_time);
            }
            if(player1.is_ballon_active()||player2.is_ballon_active())
            {

                for(int i=0;i<enemy_count;i++)
                {

                    if(collision_detector.projectile_HitsEnemy(player1.getHitbox(),BOTTOM[i]->getHIT_box()))
                    {
                        BOTTOM[i]->set_dead();
                    }
                    if(collision_detector.projectile_HitsEnemy(player2.getHitbox(),BOTTOM[i]->getHIT_box()))
                    {
                        BOTTOM[i]->set_dead();
                    }
                }

            }


            for(int i=0;i<enemy_count;i++)
            if(snowBALL_PTR!=NULL)
            {

            if(collision_detector.snowball_HitsEnemy(snowBALL_PTR->getHit_box(),BOTTOM[i]->getHIT_box()))
            {
                //we encase bottom and for the moment we do

                if(snow_checker)
                {
                    Hit_sound.play();
                    BOTTOM[i]->get_hit();
                }
               
               snow_checker=false;

            }
            }
            for(int i=0;i<enemy_count;i++)
            if(BOTTOM[i]->get_rooling())
        {
            for(int j=0;j<enemy_count;j++)
            if(collision_detector.rollingSnowball_HitsEnemy(BOTTOM[i]->getHIT_box(),BOTTOM[j]->getHIT_box()))
            {if(i!=j )
                BOTTOM[j]->set_dead();
                if(!BOTTOM[j]->check_alive())
                {
                    score_total+=100;
                    coins++;

                    //leaderboard update in realtime 

                    if(logged_In_User != "" && user_db.findByUsername(logged_In_User) && !score_saved)
                    {
                        leaderboard_db.insertScore(logged_In_User, score_total, level + 1, getTodaysDate());
                    }

                }
                
            }

        }

        bool check_level_complete=true;
        for(int i=0;i<enemy_count;i++)
        {
            if(BOTTOM[i]->check_alive())
            check_level_complete=false;

          
        }

        //  if(check_level_complete)
        //  {
        //         current_state=GameState::LEVEL_COMPLETE;
        //         level_complete_timer.restart();
        //  }

        if(check_level_complete)
{

    current_state=GameState::LEVEL_COMPLETE;
    level_complete_timer.restart();
}
            
//poerup implementation




             for(int i=0;i<enemy_count;i++)
            if(collision_detector.player_HitsEnemy(player1.getHitbox() ,BOTTOM[i]->getHIT_box())&& (player1.is_life()))
            {
                FF *ff=dynamic_cast<FF*>(BOTTOM[i]);

                if(ff!=NULL)
                ff->reset_flight();
               
                if (BOTTOM[i]->get_snow_ball_counter()>=4)
                {
                   
                    BOTTOM[i]->set_rooling(player1.left_chcker());
                    

                    // if(collision_detector.player_HitsEnemy(BOTTOM->getHIT_box(),))
                }
                else if(BOTTOM[i]->get_snow_ball_counter()==0&&(!player1.is_ballon_active()&&!player2.is_ballon_active()))
                {
                    if(player1.is_life())
                    player1.decrease_life();
                    player1.reset_position(1);
                    
                }   
                
            }

                for(int i=0;i<enemy_count;i++)
            if(collision_detector.player_HitsEnemy(player2.getHitbox() ,BOTTOM[i]->getHIT_box())&& (player2.is_life()))
            {
                FF *ff=dynamic_cast<FF*>(BOTTOM[i]);

                if(ff!=NULL)
                ff->reset_flight();
               
                if (BOTTOM[i]->get_snow_ball_counter()>=4)
                {

                    
                    BOTTOM[i]->set_rooling(player2.left_chcker());
                    

                    // if(collision_detector.player_HitsEnemy(BOTTOM->getHIT_box(),))
                }
                else if(BOTTOM[i]->get_snow_ball_counter()==0)
                {
                    if(player2.is_life())
                    player2.decrease_life();
                    player2.reset_position(2);
                    
                }
            }

            if(!player1.is_life()&&!player2.is_life())
            {
                current_state=GameState::GAME_OVER;
            }
  


            } 
        
            if(current_state==GameState::LEVEL_COMPLETE)
            {
                if(level_complete_timer.getElapsedTime().asSeconds()>2.0f)
                {

                    current_state=GameState::PLAYING;
                    level++;
                    gAme_load(level);
                    level_complete_timer.restart();


                    //saving data of the user- Minahil DB' calls

                    ///auto_save on level completion
                    if(logged_In_User != "" && user_db.findByUsername(logged_In_User))
                    {
                        progress_db.saveProgress(user_db.getUserId(), level, player1.get_lives(), coins, score_total);
                    }

                }

            }
  
            if(current_state==GameState::LEADERBOARD)
            {
                leaderboard_screen.OnActivate();
                current_state = leaderboard_screen.Update(change_in_time, window);
            }
                
            //minahils db callss 

            if(current_state==GameState::LOGIN)
              {

                    current_state = login_screen.Update(change_in_time, window);
                    if(current_state == GameState::PLAYING || current_state == GameState::CHARACTER_SELECT)
                    {
                        logged_In_User = login_screen.getLoggedInUsername();
                        if(user_db.findByUsername(logged_In_User))
                        {
                            int uid = user_db.getUserId();
                           if(progress_db.loadProgress(uid))
                    {
                        level = progress_db.getCurrentLevel() - 1;
                        score_total = progress_db.getHighScore();
                        player1.set_lives(progress_db.getLivesRemaining());
                        player2.set_lives(progress_db.getLivesRemaining());
                        gAme_load(level);
                    }
                        }
                    }
              }

            if(current_state==GameState::PAUSED)
                current_state = pause_menu_screen.Update(change_in_time, window);

            if(current_state==GameState::GAME_OVER)
            {

            if( game_over_screen.Update(change_in_time, window)==GameState::MAIN_MENU)
               {

                       //mnahil-db's calls
                    if(logged_In_User != "" && user_db.findByUsername(logged_In_User)&&!score_saved)
                    {
                        leaderboard_db.insertScore(logged_In_User, score_total, level + 1, getTodaysDate());

                            score_saved = true;
                    }
                      

                    BOTTOM = NULL;
                    level=0;
                    enemy_count = 0;
                    snowBALL_PTR=NULL;
                    snow_checker=false;
                    score_total=0;
                    score_saved=false;
                                
                    gAme_load(0);
                    player1.set_ID(1);
                    player2.set_ID(2);

                }
                current_state=game_over_screen.Update(change_in_time, window);

                       

            }
                
            if(current_state==GameState::SHOP)
            {
                scrreen_SHOP_obj.set_coins(coins);


                PowerUpType P_obj=PowerUpType::NONE;

               GameState x=scrreen_SHOP_obj.Update(change_in_time,window,P_obj);

               if(P_obj!=PowerUpType::NONE)
               {


               if(P_obj==PowerUpType::BALLOON_MODE&&coins>=35)
               {
                coins-=35;
                player1.set_powerUP("BALLOON_MODE");
                player2.set_powerUP("BALLOON_MODE");
               }
               

               if(P_obj==PowerUpType::SPEED_BOOST&&coins>=20)
               {
                coins-=20;
                player1.set_powerUP("SPEED_BOOST");
                player2.set_powerUP("SPEED_BOOST");
               }
               

               if(P_obj==PowerUpType::DISTANCE_INCREASE&&coins>=25)
               {
                coins-=25;
                player1.set_powerUP("DISTANCE_INCREASE");
                player2.set_powerUP("DISTANCE_INCREASE");
               }
               

               if(P_obj==PowerUpType::SNOWBALL_BOOST&&coins>=20)
               {
                coins-=20;
                if(snowBALL_PTR != NULL)
                {

                        snowBALL_PTR->set_P_UP(true);
                        player1.set_powerUP("SNOWBALL_BOOST");
            

                        player2.set_powerUP("SNOWBALL_BOOST");   

                }

               }
               


                
               }

                if(x != GameState::SHOP)
                {
                    current_state = x;
                }

            }


            if(current_state==GameState::STAR_EVENT)
{
if(!star_event_started)
    {
        coins += 10;
        star_event_timer.restart();
        star_event_started=true;
    }
    if(star_event_timer.getElapsedTime().asSeconds()>4.0f)
    {
        star_event_started=false;
        current_state=GameState::LEVEL_COMPLETE;
        level_complete_timer.restart();
    }
}
        
           
        
        }//(tam change in kitne sec)

        //IG ONLY 2 PLACES
        void game::display(){
    
            window.clear(sf::Color::Black);
    
            if (current_state == GameState::TRAILER) {
   
    
                
                window.draw(trailer_sprite);
                window.draw(trailer_logo_sprote);
                window.draw(MZ_Text);

  
            }
    
            if(current_state == GameState::MAIN_MENU){

                    
                    window.draw(bgSprite);

                    trailer_logo_sprote.setScale(0.3f, 0.3f);//chane later
                    trailer_logo_sprote.setPosition(900, 20);
                    window.draw(trailer_logo_sprote);

                    window.draw(B_NewGameSprite);
                    window.draw(txtNewGame);
                    window.draw(B_LoginSprite);
                    window.draw(txtLogin);
                    window.draw(B_LeaderboardSprite);
                    window.draw(txtLeaderboard);
                    window.draw(B_ExitSprite);
                    window.draw(txtExit);



                
            }
    
            if(current_state==GameState::PLAYING)
            {
                window.draw(level1_bg_sprite[level % 2]);

                if(player1.is_life())
                player1.draw(window);
                if(player2.is_life())
                player2.draw(window);

                // for (int i=0;i<platform_count;i++)
                // {
                //     platforms[i]->draw(window);
                // }

                for(int i=0;i<enemy_count;i++)
                if(BOTTOM[i]->check_alive())
                BOTTOM[i]->draw(window);

            if(!(snowBALL_PTR==NULL)&&snow_checker)
            {
                snowBALL_PTR->draw(window);
            }

            if(snowBALL_PTR != NULL && snowBALL_PTR->snowbal_checker()==false)
                {
                    delete snowBALL_PTR;
                    snowBALL_PTR = NULL;
                    snow_checker=false;
                }


            score.setString("SCORE: "+to_string(score_total));
            life.setString("P1:"+to_string(player1.get_lives())+" P2:"+to_string(player2.get_lives()));
            level_number.setString("LEVEL: "+to_string(level+1));


            window.draw(score);
            window.draw(life);
            window.draw(level_number);
           



            window.draw(Shop_sprite);
            
            }

            if(current_state == GameState::LEVEL_COMPLETE)
            {
                window.draw(level1_bg_sprite[level%2]);
                sf::Text txt;
                txt.setFont(font);
                txt.setString("LEVEL COMPLETE!");
                txt.setCharacterSize(40);
                txt.setFillColor(sf::Color::Yellow);
                txt.setPosition(400, 300);
                window.draw(txt);
            }

            if(current_state==GameState::REGISTER)
                login_screen.draw(window);

            if(current_state==GameState::CHARACTER_SELECT)
                character_screen.draw(window);

            if(current_state==GameState::LOGIN)
                login_screen.draw(window);

            if(current_state==GameState::LEADERBOARD)
                leaderboard_screen.draw(window);

            if(current_state==GameState::PAUSED)
            pause_menu_screen.draw(window);

            if(current_state==GameState::GAME_OVER)
                game_over_screen.draw(window);

            if(current_state==GameState::SHOP)
            scrreen_SHOP_obj.draw(window);

if(current_state==GameState::STAR_EVENT)
{
     window.draw(level1_bg_sprite[level%2]);
    sf::Text bonusText;
    bonusText.setFont(font);
    bonusText.setString("BONUS LEVEL!\n+10 COINS!");
    bonusText.setCharacterSize(50);
    bonusText.setFillColor(sf::Color::Red);
    bonusText.setPosition(350, 280);
    window.draw(bonusText);

}

            window.display();

           

        } //all the screen shtuff goes here 


        void game::check_event(){

            sf::Event event;
            
            while (window.pollEvent(event)) {
       
                if (event.type == sf::Event::Closed) {
         
                    window.close();
       
                }
       
                if (current_state == GameState::REGISTER || current_state == GameState::LOGIN)
                {
                    login_screen.handleEvent(event, window);
                }



                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            
                    window.close();
        
                }
                if(event.type==sf::Event::MouseButtonPressed&&current_state==GameState::MAIN_MENU){
                    if(event.mouseButton.button==sf::Mouse::Left)
                    {
                        sf::Vector2f mouse_click_position(event.mouseButton.x,event.mouseButton.y);
                        //now checkinh again each button
                        if(B_NewGameSprite.getGlobalBounds().contains(mouse_click_position))
                        current_state = GameState::REGISTER;
                        
                        if(B_LoginSprite.getGlobalBounds().contains(mouse_click_position))
                        current_state=GameState::LOGIN;

                        if(B_LeaderboardSprite.getGlobalBounds().contains(mouse_click_position))
                        current_state=GameState::LEADERBOARD;

                        if(B_ExitSprite.getGlobalBounds().contains(mouse_click_position))
                        window.close();
                    }
                }
                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::Space&& (player1.is_life()))
                {
                    THROW_SOUND.play();
                    if(snowBALL_PTR != NULL&&snowBALL_PTR->snowbal_checker()==false) {
                        delete snowBALL_PTR;
                        snowBALL_PTR = NULL;
                        snow_checker=false;
                    }
                    if(snow_checker==false&&player1.left_chcker())
                    {
                        snowBALL_PTR= new snow_ball(player1.get_positionof_player().x,(player1.get_positionof_player().y+50),true);
                        snow_checker=true;
                        if(player1.is_SNOW_PU())
                         snowBALL_PTR->set_P_UP(true);
                    }
                    else if(snow_checker==false&&player1.right_chcker())
                    {
                         snowBALL_PTR= new snow_ball(player1.get_positionof_player().x+96,(player1.get_positionof_player().y+50),false);
                        snow_checker=true;
                        if(player1.is_SNOW_PU())
                         snowBALL_PTR->set_P_UP(true);
                    }
                    player1.activate_SNOWBALL();
                    
                }

                if(event.type==sf::Event::KeyPressed&&event.key.code==sf::Keyboard::Down &&(player2.is_life()))
                {
                    THROW_SOUND.play();
                    if(snow_checker==false&&player2.left_chcker())
                    {
                        snowBALL_PTR= new snow_ball(player2.get_positionof_player().x,(player2.get_positionof_player().y+50),true);
                        snow_checker=true;
                        if(player2.is_SNOW_PU())
                        snowBALL_PTR->set_P_UP(true);
                    }
                    else if(snow_checker==false&&player2.right_chcker())
                    {
                         snowBALL_PTR= new snow_ball(player2.get_positionof_player().x+96,(player2.get_positionof_player().y+50),false);
                        snow_checker=true;
                        if(player2.is_SNOW_PU())
                        snowBALL_PTR->set_P_UP(true);
                    }
                    player2.activate_SNOWBALL();
                }
                if(event.type==sf::Event::MouseButtonPressed&&current_state==GameState::PLAYING)
                {
                    if(event.mouseButton.button==sf::Mouse::Left)
                    {
                        sf::Vector2f position_of_click_for_shop;

                        position_of_click_for_shop.x=event.mouseButton.x;
                        position_of_click_for_shop.y=event.mouseButton.y;
                        if(Shop_sprite.getGlobalBounds().contains(position_of_click_for_shop))
                        {
                            current_state=GameState::SHOP;
                        }

                    }
                }
                if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::P && current_state==GameState::PLAYING)
                {
                    current_state=GameState::PAUSED;
                }


            }

        }//updates current_state


        void game::run() {
        
            while (window.isOpen()) {
       
                check_event();

                float delta_T = game_timer.restart().asSeconds();
       
                update(delta_T);
       
                display();
    }
}
   
//HERE TOO
        void game::gAme_load(int level_number){


            if(BOTTOM!=NULL)
            {
                for(int i=0;i<enemy_count;i++)
                {
                    delete BOTTOM[i];
                }
                delete [] BOTTOM;

            }
            // if(!arr_main_levels[level_number].bonus)
            // {



            
            

                      enemy_count=arr_main_levels[level_number].T_enemies;


                        BOTTOM=new enemy_bottom*[enemy_count];

                        for(int i=0; i<enemy_count; i++)
                        {
                        if(level_number >=2 && i == enemy_count-1)
                        BOTTOM[i] = new FF(arr_main_levels[level_number].enemy_x[i], arr_main_levels[level_number].enemy_y[i], arr_main_levels[level_number].enemy_speed, "assets/Images/FlyingFoogaFoog_Orange.png");
                        else
                        BOTTOM[i] = new enemy_bottom(arr_main_levels[level_number].enemy_x[i], arr_main_levels[level_number].enemy_y[i], arr_main_levels[level_number].enemy_speed, arr_main_levels[level_number].BOTTOM_TEXTURE);

                        BOTTOM[i]->set_Dimension(platforms, platform_count);

                        BOTTOM[i]->set_nick_texture(player1.get_texture());

                        }
                        // }
                        // else
                        // {



                        // }

        }

//so the thing is level is being used in the fillloeing thinfs ^^^^
//see