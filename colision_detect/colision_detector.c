//
// Created by beloin on 16/03/23.
//

#include "../vector2.h"
#include "float.h"
#include "stdbool.h"

// Todo: Put it in a separate module
typedef struct {
    float centerX;
    float centerY;
    float radius;
} Circle;

// Just calculate if it's center distance square
bool CollideCircles(Circle *a, Circle *b) {
    float x = a->centerX - b->centerX;
    float y = a->centerY = b->centerY;
    float center_distance_sq = x * x + y * y;
    float radius = a->radius + b->radius;
    float radius_sq = radius * radius;
    return center_distance_sq <= radius_sq;
}

// TODO: Why passing it by reference?
// Get support Point as the maximum distance point of the mesh
Vector2 GetFurthestPoint(Vector2 *vertices, int vertex_size, Vector2 d) {
    float highest = -FLT_MAX;
    Vector2 support = (Vector2) {0, 0};

    for (int i = 0; i < vertex_size; ++i) {
        Vector2 *vec = vertices + i; // This works?
        float dot_product = vec->x * d.x + vec->y * d.y;

        if (dot_product > highest) {
            highest = dot_product;
            support = *vec; // Why work with pointers if we copy it later? Maybe to don't unnecessary copy before?
        }

    }

    return support;
}

Vector2 GetSupport(Vector2 *vertexA, int vertexA_size, Vector2 *vertexB, int vertexB_size, Vector2 d) {
    Vector2 support;

    Vector2 fp1 = GetFurthestPoint(vertexA, vertexA_size, d);
    Vector2 fp2 = GetFurthestPoint(vertexB, vertexB_size, d);

    return (Vector2) {fp1.x - fp2.x, fp1.y - fp2.y};
}

bool checkForCollision(Vector2 *vertexA, int sizeA, Vector2 *vertexB, int sizeB) {
    Vector2 support = GetSupport(vertexA, sizeA, vertexB, sizeB, (Vector2) {0, 0});

    Vector2 negated = support;
    Negate(&negated);
    Vector2 newDirection = negated;
}