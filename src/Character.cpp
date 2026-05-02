#include <SFML/Graphics.hpp>
#include "../include/UI/Character_Selectn.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Character Selection Test");
    
    CharacterSelect characterSelect;
    characterSelect.OnActivate();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Handle mouse click events (better than checking every frame)
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "🖱️ Left mouse clicked at position: (" 
                              << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
                }
            }
        }

        window.clear();
        characterSelect.draw(window);
        window.display();
    }

    characterSelect.OnExit();
    return 0;
}