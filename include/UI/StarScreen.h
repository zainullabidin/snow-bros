#pragma once

#include "../main/Game_state.h"
#include "../characters/powerup/PowerUp.h"
#include "Screen.h"
#include "ctime"


class StarScreen : public Screen
{

private:

    Texture textures[3];
    Sprite sprites[3];
    PowerUpType powerUpTypes[3]; // to keep track of states


    void loadRandomItems() ;


public:
    StarScreen();
    ~StarScreen();

    // original
    GameState Update(float deltaTime, RenderWindow &window) override;

    // oveloaded
    GameState Update(float deltaTime, RenderWindow &window, PowerUpType &powerUp);

    

    void OnActivate() override;
    void draw(RenderWindow &window) override;
    void OnExit() override;
};