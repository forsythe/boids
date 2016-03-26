#ifndef BOID_H
#define BOID_H

#include "defs.h"

class Boid {
public:
    Boid(float, float);
    Boid();
    float pos[2] = {0, 0};
    float targetPos[2] = {WIDTH/2, HEIGHT/2};
    float vel[2] = {1, 1};
    float theta = 0;

    void draw();
    void update();
    void steerTo(float, float);
};

#endif // BOID_H
