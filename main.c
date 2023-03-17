//
// Created by beloin on 12/03/23.
//

#include "particles/particle.h"
#include "interface/interface.h"
#include <unistd.h>
#include <stdio.h>
#include "time.h"

void runParticleSimulation() {
    float total_time = 10;
    float current_time = 0;
    float dt = 1;

    InitializeParticles();

    // Use time API to get dt to calculate the new velocity and position
    while (current_time < total_time) {
//        sleep(1);
        getchar();

        for (int i = 0; i < NUM_PARTICLES; ++i) {
            Particle *p = getParticle(i);
            Vector2 force = ComputeGravityForce(p);
            Vector2 acceleration = (Vector2) {force.x / p->mass, force.y / p->mass};

            Vector2 *velocity = &p->velocity;
            velocity->x = velocity->x + acceleration.x * dt;
            velocity->y = velocity->y + acceleration.y * dt;

            Vector2 *position = &p->position;
            position->x = position->x + velocity->x * dt;
            position->y = position->y + velocity->y * dt;
        }

        // Its showing, more or less
        ShowParticles(24, 80, getParticle(0), NUM_PARTICLES);
//        PrintParticles();
        current_time++;
    }
}


int main() {
    runParticleSimulation();
    return 0;
}