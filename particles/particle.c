#include <stdio.h>
#include <stdlib.h>
#include "../vector2.h"
#include "particle.h"

Particle particles[NUM_PARTICLES];

void PrintParticles() {
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        Particle *particle = &particles[i]; // Using & because if we don't use this, by default we will get a copy
        printf("Particle[%i] (%.2f, %.2f)\n", i, particle->position.x, particle->position.y);
    }
}

void InitializeParticles() {
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        Particle *ptr = &particles[i];
        ptr->position = (Vector2) {(float) arc4random_uniform(50), (float) arc4random_uniform(50)};
        ptr->mass = 1;
        ptr->velocity = (Vector2) {0, 0};
    }
}

Vector2 ComputeGravityForce(Particle *particle) {
    return (Vector2) {0, particle->mass * GRAVITY};
}

Particle *getParticle(int i) {
    return &particles[i];
}
