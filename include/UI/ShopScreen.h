#pragma once

#include "../main/Game_state.h"
#include "../characters/powerup/PowerUp.h"
#include"Screen.h"

class ShopScreen : public Screen
{
         int coins;

public:
    ShopScreen();
    ~ShopScreen();

    // original
    GameState Update(float deltaTime, RenderWindow& window) override;

    // oveloaded
    GameState Update(float deltaTime, RenderWindow& window, PowerUpType &powerUp);


    void OnActivate() override;
    void draw(RenderWindow& window) override;
    void OnExit() override;


void set_coins(int c);


    
};