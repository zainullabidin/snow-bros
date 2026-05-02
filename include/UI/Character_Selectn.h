

#pragma once

#include "../main/Game_state.h"
#include "../characters/player/Player.h"
#include "Screen.h"
#include "ctime"


class CharacterSelect : public Screen
{

public:
    CharacterSelect();
    ~CharacterSelect();

    // original  
    // GameState Update(float deltaTime, RenderWindow &window) override;

    // oveloaded  (will use if characters are implemented correctly)
    GameState Update(float deltaTime, RenderWindow &window /*,CharacterType &characterType*/) override;

    

    void OnActivate() override;
    void draw(RenderWindow &window) override;
    void OnExit() override;
};