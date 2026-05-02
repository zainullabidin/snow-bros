#include"../../include/UI/LoginScreen.h"


// constructor


LoginScreen::LoginScreen() : auth(nullptr) {
    loadBackground("assets/Images/Login.jpeg");
    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);
    
    // Load font
    if (!font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf")) {
        cout << "Error loading font" << endl;
    }
    
    // Initialize UI texts
    usernameText.setFont(font);
    usernameText.setCharacterSize(24);
    usernameText.setFillColor(Color::White);
    usernameText.setPosition(450, 350);
    
    passwordText.setFont(font);
    passwordText.setCharacterSize(24);
    passwordText.setFillColor(Color::White);
    passwordText.setPosition(450, 450);
    
    ErrorMsg.setFont(font);
    ErrorMsg.setCharacterSize(16);
    ErrorMsg.setFillColor(Color::Red);
    ErrorMsg.setPosition(450, 550);
    
    // Input state
    isTypingUsername = false;
    isTypingPassword = false;
    showCursor = true;
    blinkTimer = 0;
    
    // Button bounds (adjust based on your sprite)
    loginButtonBounds = FloatRect(260, 525, 230, 92);  // x, y, width, height
    registerButtonBounds = FloatRect(550, 525, 230, 92);
    
    // updateDisplay();
}

LoginScreen::~LoginScreen() {}

GameState LoginScreen::Update(float deltaTime, RenderWindow& window)
{	
    // Check for mouse click
    if (Mouse::isButtonPressed(Mouse::Left)) 
    {
        Vector2i mousePos = Mouse::getPosition(window);
        
        // Check if login button pressed
        if (mousePos.x >= 260 && mousePos.x <= 490 &&  // 364 + 300
            mousePos.y >= 525 && mousePos.y <= 617 )     // 347 + 60
        {  
            OnExit();
            return GameState::PLAYING;
        }
    }


    
    // Return current state if no button clicked
    return GameState::LOGIN;  
}


void LoginScreen::setAuth(Authentication* authManager) {
    auth = authManager;
}



void LoginScreen::OnActivate() {
    playMusic();
}


void LoginScreen::draw(RenderWindow& window) {
    window.draw(backgroundSprite);
}

void LoginScreen::OnExit() {
    stopMusic();
}
