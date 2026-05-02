// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include <iostream>
// #include "../include/UI/LoginScreen.h"

// using namespace sf;
// using namespace std;

// int main()
// {
//     RenderWindow window(VideoMode(1280, 720), "Snow Bros - REGISTER Test");
//     LoginScreen loginScreen;
    
//     // Set to REGISTER mode
//     loginScreen.setMode(GameState::REGISTER);
    
//     Clock clock;
    
//     cout << "=== REGISTER MODE TEST ===" << endl;
//     cout << "Instructions:" << endl;
//     cout << "1. Enter a new username (e.g., 'player1')" << endl;
//     cout << "2. Enter a password (e.g., 'pass123')" << endl;
//     cout << "3. Click the button or press Enter to register" << endl;
//     cout << endl;
//     cout << "After successful registration, the screen will stay in LOGIN mode." << endl;
//     cout << "Then you can login with your new credentials." << endl;
//     cout << endl;
    
//     bool registered = false;
    
//     while (window.isOpen())
//     {
//         float deltaTime = clock.restart().asSeconds();
        
//         Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == Event::Closed)
//                 window.close();
            
//             loginScreen.handleEvent(event, window);
//         }
        
//         GameState state = loginScreen.Update(deltaTime, window);
        
//         window.clear();
//         loginScreen.draw(window);
//         window.display();
        
//         // Check if we switched from REGISTER to LOGIN mode
//         if (state == GameState::LOGIN && !registered)
//         {
//             cout << "\n=== REGISTRATION COMPLETE! ===" << endl;
//             cout << "Now you can login with your new credentials." << endl;
//             cout << "Run the LOGIN test to verify." << endl;
//             registered = true;
            
//             // Keep window open to see the message
//             sleep(milliseconds(3000));
//             window.close();
//         }
//     }
    
//     return 0;
// }