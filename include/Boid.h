#ifndef BOID_H
#define BOID_H

#include "defs.h"

class Boid {
public:
    Boid(float, float);
    Boid();
    float pos[2] = {0, 0};
    float cohesionTargetPos[2] = {0, 0};
    float separationTargetPos[2] = {0, 0};
    float alignmentTargetPos[2] = {0, 0};

    float targetPosBuffer[2] = {0, 0};
    float vel[2] = {0, 0};
    float theta = 0;

    int numNeighbors = 0;
    float sumNeighborTheta = 0;

    void draw();
    void update();
    void steerTo(float, float);
    void addToTargetPosBuffer(float, float);
    void clearBuffer();
};

#endif // BOID_H
