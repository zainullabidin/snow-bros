#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML 2.6 Test - Square");
    window.setFramerateLimit(60);

    // Create a green square (100x100 pixels)
    sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
    square.setFillColor(sf::Color::Green);
    
    // Position the square in the center of the window
    // Center of square = (window width - square size) / 2
    square.setPosition(400.f - 50.f, 300.f - 50.f);

    // Main loop
    while (window.isOpen())
    {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Rendering
        window.clear();
        window.draw(square); // Draw the square
        window.display();
    }

    return 0;
}
