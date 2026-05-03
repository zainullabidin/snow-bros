#include "../../include/UI/LoginScreen.h"

// constructor
LoginScreen::LoginScreen()
{
    current_mode = GameState::LOGIN;

    // Create auth internally
    Session *session = new Session();
    auth = new Authentication(session);

    loadBackground("assets/Images/Login.jpeg");
    setBackgroundSize(1280, 720);
    backgroundSprite.setPosition(0, 0);

    // Load font
    if (!font.loadFromFile("assets/fonts/PressStart2P-Regular.ttf"))
    {
        cout << "Error loading font" << endl;
    }

    // Initialize UI texts
    usernameText.setFont(font);
    usernameText.setCharacterSize(14);
    usernameText.setFillColor(Color::White);
    usernameText.setPosition(215, 270);

    passwordText.setFont(font);
    passwordText.setCharacterSize(14);
    passwordText.setFillColor(Color::White);
    passwordText.setPosition(215, 405);

    ErrorMsg.setFont(font);
    ErrorMsg.setCharacterSize(16);
    ErrorMsg.setFillColor(Color::Red);
    ErrorMsg.setPosition(440, 650);

    // Input state
    isTypingUsername = false;
    isTypingPassword = false;
    showCursor = true;
    blinkTimer = 0;

    usernameBuffer = "";
    passwordBuffer = "";
    displayedPassword = "";

    updateDisplay();
}

LoginScreen::~LoginScreen()
{
    if (auth)
    {
        delete auth->getSession();
        delete auth;
        auth = nullptr;
    }
}

void LoginScreen::OnActivate()
{
    playMusic();
    // reset all buffers
    usernameBuffer = "";
    passwordBuffer = "";
    displayedPassword = "";

    isTypingUsername = false;
    isTypingPassword = false;

    ErrorMsg.setString("");
    updateDisplay();
}

void LoginScreen::draw(RenderWindow &window)
{
    window.draw(backgroundSprite);
    window.draw(usernameText);
    window.draw(passwordText);
    window.draw(ErrorMsg);
}

void LoginScreen::OnExit()
{
    stopMusic();
}

void LoginScreen::handleTextInput(Event &event, string &output, bool isPassword)
{
    if (event.type == Event::TextEntered)
    {
        // backspace func if there is something written
        if (event.text.unicode == 8 && output.length() > 0)
        {
            output.pop_back();
        }

        // Handle regular characters (not Enter, Esc, etc.)
        else if (event.text.unicode >= 32 && event.text.unicode < 127 && output.length() < 15)
        {
            // convert the availaible digit to character
            char ch = static_cast<char>(event.text.unicode);
            if (ch >= ' ' && ch <= '~')
            {
                output += ch;
            }
        }

        // ALWAYS update the display after any input
        if (isPassword)
        {
            // mask with asteriks
            displayedPassword = string(output.length(), '*');
            passwordText.setString(displayedPassword + (isTypingPassword && showCursor ? "_" : ""));
        }

        // if uname
        else
        {
            usernameText.setString(output + (isTypingUsername && showCursor ? "_" : ""));
        }
    }


    
    // Return current state if no button clicked
    return;  
}

void LoginScreen::updateDisplay()
{
    usernameText.setString(usernameBuffer + (isTypingUsername && showCursor ? "_" : ""));
    displayedPassword = string(passwordBuffer.length(), '*');
    passwordText.setString(displayedPassword + (isTypingPassword && showCursor ? "_" : ""));
}

void LoginScreen::processLogin(RenderWindow &window)
{
    ErrorMsg.setFillColor(Color::Red);

    if (!auth)
    {
        ErrorMsg.setString("System error: No auth manager!");
        return;
    }

    AuthResult result = auth->login(usernameBuffer, passwordBuffer);

    switch (result)
    {
    case AuthResult::SUCCESS:
        ErrorMsg.setFillColor(Color::Green);
        ErrorMsg.setString("Login successful!");
        break;

    case AuthResult::NOT_FOUND:
        ErrorMsg.setString("User not found! Please register first.");
        break;

    case AuthResult::WRONG_PASS:
        ErrorMsg.setString("Wrong password! Please try again.");
        break;

    case AuthResult::INVALID_INPUT:
        ErrorMsg.setString("Please enter both username and password!");
        break;

    default:
        ErrorMsg.setString("Login failed! Please try again.");
        break;
    }
}

void LoginScreen::processRegister(RenderWindow &window)
{
    ErrorMsg.setFillColor(Color::Red);
    if (!auth)
    {
        ErrorMsg.setString("System error: No auth manager!");
        return;
    }

    AuthResult result = auth->registerUser(usernameBuffer, passwordBuffer);

    switch (result)
    {
    case AuthResult::SUCCESS:
        ErrorMsg.setFillColor(Color::Green);
        ErrorMsg.setString("Sucess! Press login to continue.");
        // clear buffer

        usernameBuffer = "";
        passwordBuffer = "";
        displayedPassword = "";
        updateDisplay();
        break;

    case AuthResult::ALREADY_TAKEN:
        ErrorMsg.setString("Username already taken! Please choose another.");
        break;

    case AuthResult::INVALID_INPUT:
        ErrorMsg.setString("Please enter both username and password!");
        break;

    default:
        ErrorMsg.setString("Registration failed! Please try again.");
        break;
    }
}

GameState LoginScreen::Update(float deltaTime, RenderWindow &window)
{
    // Update cursor blink
    blinkTimer += deltaTime;
    if (blinkTimer >= 0.5f)
    {
        showCursor = !showCursor;
        blinkTimer = 0;
        updateDisplay();
    }

    // Check for button clicks (using mouse button state)
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i mousePos = Mouse::getPosition(window);

        // Login / reg button
        if ((mousePos.x >= 260 && mousePos.x <= 490) && (mousePos.y >= 525 && mousePos.y <= 617))
        {
            if (current_mode == GameState::LOGIN)
                processLogin(window);

            // Check if login was successful
            if (auth && auth->isLoggedIn())
            {
                // Wait a moment to show success message
                sleep(milliseconds(500));
                OnExit();
                return GameState::PLAYING;
            }

            else if (current_mode == GameState::REGISTER)
                processRegister(window);
        }
    }

    // login / reg
    return current_mode;
}

void LoginScreen::handleEvent(Event &event, RenderWindow &window)
{
    if (event.type == Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == Mouse::Left)
        {
            Vector2i mousePos = Mouse::getPosition(window);

            // Username territory of dehshat
            if (mousePos.x >= 210 && mousePos.x <= 550 && mousePos.y >= 255 && mousePos.y <= 300)
            {
                isTypingUsername = true;
                isTypingPassword = false;
                showCursor = true;
                blinkTimer = 0;
                updateDisplay();
            }

            // Password - sneaky territory
            else if (mousePos.x >= 200 && mousePos.x <= 550 && mousePos.y >= 370 && mousePos.y <= 440)
            {
                isTypingUsername = false;
                isTypingPassword = true;
                showCursor = true;
                blinkTimer = 0;
                updateDisplay();
            }

            else
            {
                isTypingUsername = false;
                isTypingPassword = false;
                updateDisplay();
            }
        }
    }

    else if (event.type == sf::Event::TextEntered)
    {
        if (isTypingUsername)
        {
            handleTextInput(event, usernameBuffer, false);
        }
        else if (isTypingPassword)
        {
            handleTextInput(event, passwordBuffer, true);
        }
    }

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
    {
        // aftter typing pass, check for conditions
        if (isTypingPassword)
        {
            processLogin(window);
        }
    }
}

void LoginScreen::setMode(GameState mode)
{
    current_mode = mode;
}
