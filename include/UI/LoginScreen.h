#pragma once

#include "../main/Game_state.h"
#include "../auth/Authentication_Manager.h"
#include "Screen.h"

class LoginScreen : public Screen
{
private:

    Authentication* auth;

    Text usernameText;
    Text passwordText;
    Text ErrorMsg;
    Font font;

    // setter
    void setAuth(Authentication* authManager);

    // Input tracking
    bool isTypingUsername;
    bool isTypingPassword;
    float blinkTimer;
    bool showCursor;
    
    // Button bounds
    FloatRect loginButtonBounds;
    FloatRect registerButtonBounds;

    // void handleTextInput(sf::Event &event);
    // void processLogin(RenderWindow &window);
    // void processRegister(RenderWindow &window);
    // void updateDisplay();

public:
    LoginScreen();
    ~LoginScreen();

    GameState Update(float deltaTime, RenderWindow &window) override;
    void OnActivate() override;
    void draw(RenderWindow &window) override;
    void OnExit() override;
};