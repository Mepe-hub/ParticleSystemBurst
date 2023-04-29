//
//  Particles.cpp
//  Particles
//
//  Created by Andreas Reinbott on 29.04.23.
//  Copyright © 2023 Andreas Reinbott. All rights reserved.
//

#include <stdio.h>
#include "Particles.h"

Particle::Particle(sf::Vector2f direction)
{
    //Determine the direction
    m_Velocity.x = direction.x;
    m_Velocity.y = direction.y;
    
}

void Particle::update(float dtAsSeconds)
{
    //Move the particle
    m_Position += m_Velocity * dtAsSeconds;
}

void Particle::setPosition(sf::Vector2f position)
{
    m_Position = position;
}

sf::Vector2f Particle::getPosition()
{
    return m_Position;
}

