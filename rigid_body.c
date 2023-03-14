//
// Created by beloin on 11/03/23.
//

#include "vector2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define NUM_RIGID_BODIES 1

// List of moments of inertia: https://en.wikipedia.org/wiki/List_of_moments_of_inertia
typedef struct BoxShape {
    float width;
    float height;
    float mass;
    float moment_of_inertia;
} BoxShape;


void CalculateBoxInertia(BoxShape *boxShape) {
    float d_height = boxShape->height * boxShape->height;
    float d_width = boxShape->width * boxShape->width;
    float mass = boxShape->mass;

    float m_inertia = (mass * (d_height + d_width)) / 12;

    boxShape->moment_of_inertia = m_inertia;
}

typedef struct {
    Vector2 position;
    Vector2 linear_velocity;

    float angle;
    float angular_velocity;

    Vector2 force;
    float torque;

    // This means we can use a container of box shapes to use our "design"
    BoxShape shape;
} RigidBody;

RigidBody rigid_bodies[NUM_RIGID_BODIES];

void PrintRigidBodies() {
    for (int i = 0; i < NUM_RIGID_BODIES; ++i) {
        RigidBody *rigid_body = &rigid_bodies[i];
        float xp = rigid_body->position.x;
        float yp = rigid_body->position.y;
        float angle = rigid_body->angle;
        printf("RigidBody[%i] p = {%.2f, %.2f}, a = %.2f\n", i, xp, yp, angle);
    }
}

void InitializeRigidBodies() {
    for (int i = 0; i < NUM_RIGID_BODIES; ++i) {
        RigidBody *rigid_body = &rigid_bodies[i];
        rigid_body->position = (Vector2) {(float) arc4random_uniform(50), (float) arc4random_uniform(50)};
        rigid_body->angle = (float) (((float) arc4random_uniform(360)) / 360 * M_PI * 2); // y = (x*2pi)/360
        rigid_body->linear_velocity = (Vector2) {0, 0};
        rigid_body->angular_velocity = 0;

        BoxShape box_shape;
        box_shape.mass = 10;
        box_shape.width = (float) (1 + arc4random_uniform(2));
        box_shape.height = (float) (1 + arc4random_uniform(2));
        CalculateBoxInertia(&box_shape);

        rigid_body->shape = box_shape;
    }
}

void ComputeForceAndTorque(RigidBody *rigid_body) {
    Vector2 force = (Vector2) {0, 100}; // 100 Newtons of force
    rigid_body->force = force;

    // Using an "arm vector"
    Vector2 r = (Vector2) {rigid_body->shape.width / 2, rigid_body->shape.height / 2};
    rigid_body->torque = r.x * force.y - r.y * force.x;
}

void runRigidBodiesSimulation() {
    float totalSimulationTime = 10;
    float currentTime = 0;
    float dt = 1;

    InitializeRigidBodies();
    PrintRigidBodies();

    while (currentTime < totalSimulationTime) {
        sleep(dt);

        for (int i = 0; i < NUM_RIGID_BODIES; ++i) {
            RigidBody *rigidBody = &rigid_bodies[i];
            ComputeForceAndTorque(rigidBody);
            Vector2 linearAcceleration = (Vector2) {rigidBody->force.x / rigidBody->shape.mass,
                                                    rigidBody->force.y / rigidBody->shape.mass};

            rigidBody->linear_velocity.x += linearAcceleration.x * dt;
            rigidBody->linear_velocity.y += linearAcceleration.y * dt;
            rigidBody->position.x += rigidBody->linear_velocity.x * dt;
            rigidBody->position.y += rigidBody->linear_velocity.y * dt;


            float angularAcceleration = rigidBody->torque / rigidBody->shape.moment_of_inertia;
            rigidBody->angular_velocity += angularAcceleration * dt;
            rigidBody->angle += rigidBody->angular_velocity * dt;
        }

        PrintRigidBodies();
        currentTime += dt;
    }
}
