#pragma once

#include "../main/Game_state.h"
#include "../auth/Authentication_Manager.h"
#include "Screen.h"

class LoginScreen : public Screen
{
private:
    Authentication* auth;       
    
    GameState current_mode;


    Text usernameText;
    Text passwordText;
    Text ErrorMsg;
    Font font;

    // Input state
    string usernameBuffer;
    string passwordBuffer;
    string displayedPassword;
    
    // Input tracking
    bool isTypingUsername;
    bool isTypingPassword;
    float blinkTimer;
    bool showCursor;
    
    // simple login dekhne ke liye
    void handleTextInput(Event &event, string& output, bool isPassword);
    void processLogin(RenderWindow &window);
    void processRegister(RenderWindow &window);
    void updateDisplay();
    

public:
    LoginScreen();  
    ~LoginScreen();

    void setMode(GameState mode);


    // check for in boxes etc
    void handleEvent(Event& event, RenderWindow& window);  


    GameState Update(float deltaTime, RenderWindow &window) override;
    void OnActivate() override;
    void draw(RenderWindow &window) override;
    void OnExit() override;
};


