//
//  ParticleSystem.cpp
//  Particles
//
//  Created by Andreas Reinbott on 29.04.23.
//  Copyright © 2023 Andreas Reinbott. All rights reserved.
//

#include "ParticleSystem.hpp"
#include "Particles.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <chrono>

ParticleSystem::ParticleSystem(int numParticles)
    : m_Vertices(sf::Points, numParticles)
    , m_IsRunning(false)
    , m_Duration(5.0f) // set duration to 5 seconds
{
    // particle initialization code here
        m_Vertices.setPrimitiveType(sf::Points);
        m_Vertices.resize(numParticles);
        
        //random numbers
        
           std::mt19937 rng(m_seed);
           std::uniform_int_distribution<int> angleGen(0, 360); // uniform, unbiased
        std::uniform_int_distribution<int> speedGen(0, 500);

        //create the particles
           
        for(size_t i = 0; i < numParticles; i++)
        {
            int r1 = angleGen(rng);
            int r2 = speedGen(rng);
           
            float angle = r1 * (3.14f / 180.f);
            float speed = r2 + 20.f;
            
            sf::Vector2f direction;
            
            direction = sf::Vector2f(cos(angle) * speed, sin(angle) * speed);
            
            //new Particle instance is stored in m_Particles; a call to init function with a value of 1000 creates 1000 instances of Particle with random velocity
            m_Particles.push_back(Particle(direction));
        }
    }



void ParticleSystem::update(float dt)
{
    std::vector<Particle>::iterator i;
    int currentVertex = 0;
    m_Duration -= dt;
    for(i = m_Particles.begin(); i!= m_Particles.end(); i++)
    {
        //Move the particle
        (*i).update(dt);
        
        //Update the vertex array
        m_Vertices[currentVertex].position = (*i).getPosition();
        
        //Move to the next vertex
        currentVertex++;
    }
    
    //check whether it is time to switch off the effect
    if(m_Duration < 0) m_IsRunning = false;
    
}

void ParticleSystem::emitParticles(sf::Vector2f startPosition)
{
    m_IsRunning = true;
    m_Duration = 5.0f;
    
    std::vector<Particle>::iterator i;
    int currentVertex = 0;
    std::mt19937 rng(40);
    std::uniform_int_distribution<int> colorGen(0, 180); // uniform, unbiased
    for(i = m_Particles.begin(); i!= m_Particles.end(); i++)
    {
        int r = colorGen(rng);
        m_Vertices[currentVertex].color = sf::Color(230, r, r, 255);
                m_Vertices[currentVertex + 1].color = sf::Color(230, r, r, 255);
                m_Vertices[currentVertex + 2].color = sf::Color(230, r, r, 255);
                m_Vertices[currentVertex + 3].color = sf::Color(230, r, r, 255);
       // m_Vertices[currentVertex].color = sf::Color(r, r, 20, 255);
        (*i).setPosition(startPosition);
        
        currentVertex++;
    }
    
}


void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Vertices, states);
}

bool ParticleSystem::running()
{
    return m_IsRunning;
}

