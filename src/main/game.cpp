#include "../../include/main/game.h"
#include "../../include/UI/LeaderboardScreen.h"



game::game() 
{

    level = 0;
    snowBALL_PTR = NULL;
    snow_checker = false;

    
    window.create(sf::VideoMode(1280, 720), "SNOW BROS-By MZ"); // screens saz and apna mark
    


    font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf");
    // maim menu content loacer
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

    // adding sprites for main menu

    B_LoginSprite.setTexture(B_Frame_texture);
    B_LoginSprite.setScale(B_Scale_X, B_Scale_Y);
    B_LoginSprite.setPosition(300, 320);

    B_LeaderboardSprite.setTexture(B_Frame_texture);
    B_LeaderboardSprite.setScale(B_Scale_X, B_Scale_Y);
    B_LeaderboardSprite.setPosition(300, 420);

    B_ExitSprite.setTexture(B_Frame_texture);
    B_ExitSprite.setScale(B_Scale_X, B_Scale_Y);
    B_ExitSprite.setPosition(300, 520);

    // logo
    trailer_logo_textture.loadFromFile("assets/images/title+logo.png");
    trailer_logo_sprote.setTexture(trailer_logo_textture);
    trailer_logo_sprote.setScale(0.8f, 0.8f);
    trailer_logo_sprote.setPosition(300, 150);

    tariler_bg_Textture.loadFromFile("assets/images/trailer_bg.png");
    trailer_sprite.setTexture(tariler_bg_Textture);
    trailer_sprite.setScale(1280.0f / tariler_bg_Textture.getSize().x, 720.0f / tariler_bg_Textture.getSize().y);
    // bg load
    bgTexture.loadFromFile("assets/images/background.png");

    current_state = GameState::TRAILER;

    // clcik button-1

    txtNewGame.setFont(font);
    txtNewGame.setString("NEW GAME");
    txtNewGame.setCharacterSize(22);

    // btn-2

    txtLogin.setFont(font);
    txtLogin.setString("LOGIN");
    txtLogin.setCharacterSize(22);
    txtLogin.setPosition(430, 345);

    // bten-3

    txtLeaderboard.setFont(font);
    txtLeaderboard.setCharacterSize(22);
    txtLeaderboard.setString("LEADERBOARD");
    txtLeaderboard.setPosition(390, 445);

    // btn-4

    txtExit.setFont(font);
    txtExit.setString("EXIT");
    txtExit.setCharacterSize(22);
    txtExit.setPosition(430, 545);

    bgSprite.setTexture(bgTexture);
    // scaling acc to size
    bgSprite.setScale(1280.0f / bgTexture.getSize().x, 720.0f / bgTexture.getSize().y);

    MZ_Text.setFont(font);
    MZ_Text.setString("Made by Minahil & Zain");
    MZ_Text.setCharacterSize(16);
    MZ_Text.setFillColor(sf::Color(10, 10, 80));
    MZ_Text.setPosition(400, 500);

    player1.set_ID(1);

    player2.set_ID(2);

    // level 01
    level1_bg_texture.loadFromFile("assets/Images/level1.png");
    level1_bg_sprite.setTexture(level1_bg_texture);

    // scale on level1
    level1_bg_sprite.setScale(1280.0f / level1_bg_texture.getSize().x, 720.0f / level1_bg_texture.getSize().y);

    // the jumping bars thingy&

    /// each bar dimensions

    platform_count = 7;

    platforms[0] = new dimension_er(130, 693, 1020, 30); // ground
    platforms[1] = new dimension_er(135, 580, 230, 30);  // brtonm left one
    platforms[2] = new dimension_er(920, 580, 230, 30);  // right_(BOTTOM)
    platforms[3] = new dimension_er(320, 475, 640, 30);  //  THE CENTER ONE
    platforms[4] = new dimension_er(130, 370, 425, 30);  // up -left opne
    platforms[5] = new dimension_er(720, 370, 425, 30);  /// up_right one
    platforms[6] = new dimension_er(525, 585, 245, 30);  // bootom middle
    player1.set_Dimension(platforms, platform_count);

    // bottom

    BOTTOM[0] = new enemy_bottom(130, 300);  // top_left
    BOTTOM[1] = new enemy_bottom(1000, 300); // top-iRght
    BOTTOM[2] = new enemy_bottom(130, 600);

    BOTTOM[0]->set_Dimension(platforms, platform_count);
    BOTTOM[1]->set_Dimension(platforms, platform_count);
    BOTTOM[2]->set_Dimension(platforms, platform_count);
    BOTTOM[0]->set_nick_texture(player1.get_texture());
    BOTTOM[1]->set_nick_texture(player1.get_texture());
    BOTTOM[2]->set_nick_texture(player1.get_texture());
}

void game::update(float change_in_time)
{

    if (current_state == GameState::TRAILER)
    {

        if (trailer_timer.getElapsedTime().asSeconds() >= 5.0f)
        {

            current_state = GameState::MAIN_MENU;
        }
    }

    if (current_state == GameState::LEADERBOARD)
    {
        current_state = leaderboard_screen.Update(change_in_time, window);
    }

    if (current_state == GameState::LOGIN)
    {
        current_state = login_screen.Update(change_in_time, window);
    }

    if (current_state == GameState::PAUSED)
    {
        current_state = pause_menu_screen.Update(change_in_time, window);
    }

    if (current_state == GameState::PLAYING)
    {
        player1.update_sprite_position(change_in_time);
        for (int I = 0; I < 3; I++)
        {
            {
                if (BOTTOM[I]->check_alive())
                    BOTTOM[I]->update_sprite_position(change_in_time);
            }
        }

        if (!(snowBALL_PTR == NULL) && snow_checker)
        {
            snowBALL_PTR->update_sprite_position(change_in_time);
        }

        for (int i = 0; i < 3; i++)
            if (snowBALL_PTR != NULL)
            {

                if (collision_detector.snowball_HitsEnemy(snowBALL_PTR->getHit_box(), BOTTOM[i]->getHIT_box()))
                {
                    // we encase bottom and for the moment we do

                    if (snow_checker)
                    {
                        BOTTOM[i]->get_hit();
                    }

                    snow_checker = false;
                }
            }
        for (int i = 0; i < 3; i++)
            if (BOTTOM[i]->get_rooling())
            {
                for (int j = 0; j < 3; j++)
                    if (collision_detector.rollingSnowball_HitsEnemy(BOTTOM[i]->getHIT_box(), BOTTOM[j]->getHIT_box()))
                    {
                        if (i != j)
                            BOTTOM[j]->set_dead();
                    }
            }

        bool check_level_complete = true;
        for (int i = 0; i < 3; i++)
        {
            if (BOTTOM[i]->check_alive())
                check_level_complete = false;
        }

        if (check_level_complete)
        {
            current_state = GameState::LEVEL_COMPLETE;
            level_complete_timer.restart();
        }

        for (int i = 0; i < 3; i++)
            if (collision_detector.player_HitsEnemy(player1.getHitbox(), BOTTOM[i]->getHIT_box()))
            {

                if (BOTTOM[i]->get_snow_ball_counter() >= 4)
                {
                    BOTTOM[i]->set_rooling(player1.left_chcker());

                    // if(collision_detector.player_HitsEnemy(BOTTOM->getHIT_box(),))
                }
                else if (BOTTOM[i]->get_snow_ball_counter() == 0)
                {
                    player1.decrease_life();
                }
            }
        if (!player1.is_life())
        {
            current_state = GameState::GAME_OVER;
        }
    }


    if (current_state == GameState::GAME_OVER)
    {
        current_state = game_over_screen.Update(change_in_time, window);
    }


    if (current_state == GameState::LEVEL_COMPLETE)
    {
        if (level_complete_timer.getElapsedTime().asSeconds() > 2.0f)
        {

            current_state = GameState::PLAYING;
            level++;
            level_complete_timer.restart();
        }
    }

} //(tam change in kitne sec)

void game::display()
{

    window.clear(sf::Color::Black);

    if (current_state == GameState::TRAILER)
    {

        window.draw(trailer_sprite);
        window.draw(trailer_logo_sprote);
        window.draw(MZ_Text);
    }

    if (current_state == GameState::MAIN_MENU)
    {

        window.draw(bgSprite);

        trailer_logo_sprote.setScale(0.3f, 0.3f); // chane later
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

    if (current_state == GameState::LOGIN)
    {
        // login_screen.OnActivate();
        login_screen.draw(window);
    }

    if (current_state == GameState::LEADERBOARD){
        leaderboard_screen.OnActivate();
        leaderboard_screen.draw(window);
    }

    if (current_state == GameState::PAUSED){
        // pause_menu_screen.OnActivate();
        pause_menu_screen.draw(window);
    }

    if (current_state == GameState::PLAYING)
    {

        window.draw(level1_bg_sprite);
        if (player1.is_life())
            player1.draw(window);

        // for (int i=0;i<platform_count;i++)
        // {
        //     platforms[i]->draw(window);
        // }

        for (int i = 0; i < 3; i++)
            if (BOTTOM[i]->check_alive())
                BOTTOM[i]->draw(window);

        if (!(snowBALL_PTR == NULL) && snow_checker)
        {
            snowBALL_PTR->draw(window);
        }

        if (snowBALL_PTR != NULL && snowBALL_PTR->snowbal_checker() == false)
        {
            delete snowBALL_PTR;
            snowBALL_PTR = NULL;
            snow_checker = false;
        }
    }

    if (current_state == GameState::GAME_OVER)
    {
        // game_over_screen.OnActivate();   activate on adding sound
        game_over_screen.draw(window);
    }

    if (current_state == GameState::LEVEL_COMPLETE)
    {
        window.draw(level1_bg_sprite);
        sf::Text txt;
        txt.setFont(font);
        txt.setString("LEVEL COMPLETE!");
        txt.setCharacterSize(40);
        txt.setFillColor(sf::Color::Yellow);
        txt.setPosition(400, 300);
        window.draw(txt);
    }

    window.display();

} // all the screen shtuff goes here

void game::check_event()
{

    sf::Event event;

    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
        {

            window.close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {

            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && current_state == GameState::MAIN_MENU)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mouse_click_position(event.mouseButton.x, event.mouseButton.y);
                // now checkinh again each button
                if (B_NewGameSprite.getGlobalBounds().contains(mouse_click_position))
                    current_state = GameState::PLAYING;
                if (B_LoginSprite.getGlobalBounds().contains(mouse_click_position))
                    current_state = GameState::LOGIN;
                if (B_LeaderboardSprite.getGlobalBounds().contains(mouse_click_position))
                    current_state = GameState::LEADERBOARD;
                if (B_ExitSprite.getGlobalBounds().contains(mouse_click_position))
                    window.close();
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            if (snowBALL_PTR != NULL && snowBALL_PTR->snowbal_checker() == false)
            {
                delete snowBALL_PTR;
                snowBALL_PTR = NULL;
                snow_checker = false;
            }
            if (snow_checker == false && player1.left_chcker())
            {
                snowBALL_PTR = new snow_ball(player1.get_positionof_player().x, (player1.get_positionof_player().y + 50), true);
                snow_checker = true;
            }
            else if (snow_checker == false && player1.right_chcker())
            {
                snowBALL_PTR = new snow_ball(player1.get_positionof_player().x + 96, (player1.get_positionof_player().y + 50), false);
                snow_checker = true;
            }
            player1.activate_SNOWBALL();
        }
    }

} // updates current_state

void game::run()
{

    while (window.isOpen())
    {

        check_event();

        float delta_T = game_timer.restart().asSeconds();

        update(delta_T);

        display();
    }
}
