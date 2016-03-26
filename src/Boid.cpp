#include <math.h>

#include "Boid.h"
#include "CSDLManagerLite.h"
#include "defs.h"

Boid::Boid(float x, float y) {
    pos[0] = x;
    pos[1] = y;
}

Boid::Boid() {
    pos[0] = rand()%WIDTH;
    pos[1] = rand()%HEIGHT;
    //vel[0] = (rand()%100)/100.0;
    //vel[1] = (rand()%100)/100.0;
}

void Boid::draw() {
    CSDLManagerLite::getInstance() -> drawTriangle(pos[0], pos[1], bWIDTH, bHEIGHT, theta);
    CSDLManagerLite::getInstance() -> drawCircle(pos[0], pos[1], BOID_RADIUS);
}

void Boid::update() {
    steerTo(targetPos[0], targetPos[1]);

    pos[0] += vel[0];
    pos[1] += vel[1];

    if (pos[0] > WIDTH) pos[0] = 1;
    if (pos[0] <= 0) pos[0] = WIDTH;

    if (pos[1] > HEIGHT) pos[1] = 1;
    if (pos[1] <= 0) pos[1] = HEIGHT;

    theta = atan2(-vel[1], vel[0]);
}
