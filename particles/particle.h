//
// Created by beloin on 12/03/23.
//

#ifndef INC_2D_PHYSICS_PARTICLE_H
#define INC_2D_PHYSICS_PARTICLE_H

#define NUM_PARTICLES 5
#define GRAVITY 9.8

#include "../vector2.h"

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle;

void PrintParticles();
void InitializeParticles();
Vector2 ComputeGravityForce(Particle *particle);
Particle *getParticle(int i);

#endif //INC_2D_PHYSICS_PARTICLE_H
