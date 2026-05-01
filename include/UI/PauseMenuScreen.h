#pragma once

#include "../main/Game_state.h"
#include"Screen.h"

class PauseMenuScreen : public Screen
{

public:
    PauseMenuScreen();
    ~PauseMenuScreen();


    GameState Update(float deltaTime, RenderWindow& window) override;
    void OnActivate() override;
    void draw(RenderWindow& window) override;
    void OnExit() override;
    
};