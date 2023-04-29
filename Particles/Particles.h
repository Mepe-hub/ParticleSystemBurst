//
//  Particles.h
//  Particles
//
//  Created by Andreas Reinbott on 09.04.23.
//  Copyright © 2023 Andreas Reinbott. All rights reserved.
//

#ifndef Particles_h
#define Particles_h

#include <SFML/Graphics.hpp>


class Particle {
public:
    
    
    Particle(sf::Vector2f direction);
    
    void update(float dt);
    
    void setPosition(sf::Vector2f position);
    
    sf::Vector2f getPosition();
    
    
private:
   
    sf::Vector2f m_Position;
    sf::Vector2f m_Velocity;
    
};

#endif /* Particles_h */
