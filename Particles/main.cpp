
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Particles.h"
#include "ParticleSystem.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Default);
    
    //create text
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString("Particle Blast");
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(350, 300);
    
    //create single instance of particle
    ParticleSystem m_PS(8000);

    // Set up the clock for timing
        sf::Clock clock;
        sf::Time deltaTime = clock.restart();
  
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
                       {
                           if (event.mouseButton.button == sf::Mouse::Left)
                           {
                               
                               //position of emission
                               sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                               m_PS.emitParticles(mousePos);
                           }
                       }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
          
        }
       
        window.clear();
        
        
        // Draw the particles
       
        if(m_PS.running())
        {
            deltaTime = clock.restart();
            m_PS.update(deltaTime.asSeconds());
            window.draw(m_PS);
        }
        else if(!m_PS.running())
        {
            
            window.draw(text);
        }

        // Update the window
        window.display();
        
       
    }

    return EXIT_SUCCESS;
}
