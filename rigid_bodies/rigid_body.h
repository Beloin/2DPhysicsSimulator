//
// Created by beloin on 14/03/23.
//

#ifndef INC_2D_PHYSICS_RIGID_BODY_H
#define INC_2D_PHYSICS_RIGID_BODY_H

#include "../vector2.h"

// List of moments of inertia: https://en.wikipedia.org/wiki/List_of_moments_of_inertia
// TODO: Try to implement another one
typedef struct BoxShape {
    float width;
    float height;
    float mass;
    float moment_of_inertia;
} BoxShape;


// TODO: Change for creation of BoxShape
void CalculateBoxInertia(BoxShape *boxShape);

typedef struct {
    Vector2 position;
    Vector2 linear_velocity;

    float angle;
    float angular_velocity;

    Vector2 force;
    float torque;

    // This means we can use a container of box shapes to use our "design"
    BoxShape shape;
} BoxRigidBody;

#endif //INC_2D_PHYSICS_RIGID_BODY_H
