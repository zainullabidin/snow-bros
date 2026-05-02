// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include <iostream>
// #include "../include/UI/LoginScreen.h"

// using namespace sf;
// using namespace std;

// int main()
// {
//     RenderWindow window(VideoMode(1280, 720), "Snow Bros - LOGIN Test");
//     LoginScreen loginScreen;
    
//     // Set to LOGIN mode
//     loginScreen.setMode(GameState::LOGIN);
    
//     Clock clock;
    
//     cout << "=== LOGIN MODE TEST ===" << endl;
//     cout << "First, register a user using REGISTER test!" << endl;
//     cout << "Then come back to this test to login." << endl;
//     cout << endl;
//     cout << "Instructions:" << endl;
//     cout << "1. Click on username field and type your username" << endl;
//     cout << "2. Click on password field and type your password" << endl;
//     cout << "3. Click the button or press Enter to login" << endl;
//     cout << endl;
    
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
        
//         if (state == GameState::PLAYING)
//         {
//             cout << "\n=== LOGIN SUCCESSFUL! ===" << endl;
//             sleep(milliseconds(2000));
//             window.close();
//         }
//     }
    
//     return 0;
// }