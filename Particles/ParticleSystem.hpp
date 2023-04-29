//
//  ParticleSystem.hpp
//  Particles
//
//  Created by Andreas Reinbott on 29.04.23.
//  Copyright © 2023 Andreas Reinbott. All rights reserved.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include "Particles.h"
#include <SFML/Graphics.hpp>


class ParticleSystem : public sf::Drawable
{
public:
    ParticleSystem(int numParticles);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void emitParticles (sf::Vector2f position);
    void update (float elapsed);
    bool running();
 
    
private:
    
    std::vector<Particle> m_Particles;
    sf::VertexArray m_Vertices;
    unsigned m_seed = std::chrono::system_clock::now().time_since_epoch().count();
    float m_Duration;
    bool m_IsRunning = false;
};

#endif /* ParticleSystem_hpp */
