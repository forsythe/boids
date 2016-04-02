#include <math.h>
#include <iostream>

#include "Boid.h"
#include "CSDLManagerLite.h"
#include "defs.h"

using namespace std;

Boid::Boid(float x, float y) {
    pos[0] = x;
    pos[1] = y;
    vel[0] = (100-(rand()%200))/100.0;
    vel[1] = (100-(rand()%200))/100.0;
}

Boid::Boid() {
    pos[0] = rand()%WIDTH;
    pos[1] = rand()%HEIGHT;
    vel[0] = (100-(rand()%200))/100.0;
    vel[1] = (100-(rand()%200))/100.0;
}

void Boid::draw() {
    CSDLManagerLite::getInstance() -> drawTriangle(pos[0], pos[1], bWIDTH, bHEIGHT, theta);
    if (DRAW_RADIUS) {
        CSDLManagerLite::getInstance() -> drawCircle(pos[0], pos[1], BOID_RADIUS);
        CSDLManagerLite::getInstance() -> drawCircle(pos[0], pos[1], SEPARATION_BOID_RADIUS);
    }

    if (DRAW_VECTOR) {
        CSDLManagerLite::getInstance() -> drawCircle(cohesionTargetPos[0], cohesionTargetPos[1], 10);
        CSDLManagerLite::getInstance() -> drawLine(pos[0], pos[1], cohesionTargetPos[0], cohesionTargetPos[1]);

        CSDLManagerLite::getInstance() -> drawCircle(separationTargetPos[0], separationTargetPos[1], 10);
        CSDLManagerLite::getInstance() -> drawLine(pos[0], pos[1], separationTargetPos[0], separationTargetPos[1]);

        }
        CSDLManagerLite::getInstance() -> drawCircle(alignmentTargetPos[0], alignmentTargetPos[1], 10);
        CSDLManagerLite::getInstance() -> drawLine(pos[0], pos[1], alignmentTargetPos[0], alignmentTargetPos[1]);

}

void Boid::update() {
    steerTo(cohesionTargetPos[0]*W_COHESION + separationTargetPos[0]*W_SEPARATION + alignmentTargetPos[0]*W_ALIGNMENT,
            cohesionTargetPos[1]*W_COHESION + separationTargetPos[1]*W_SEPARATION + alignmentTargetPos[1]*W_ALIGNMENT);

    //cout << targetPos[0] << " " << targetPos[1] << endl;

    pos[0] += vel[0];
    pos[1] += vel[1];

    if (pos[0] >= WIDTH) pos[0] = 1;
    if (pos[0] <= 0) pos[0] = WIDTH;

    if (pos[1] >= HEIGHT) pos[1] = 1;
    if (pos[1] <= 0) pos[1] = HEIGHT;

    theta = atan2(-vel[1], vel[0]);

    if (theta < 0)
        theta += 2*PI;
}

void Boid::addToTargetPosBuffer(float x, float y) {
    targetPosBuffer[0] += x;
    targetPosBuffer[1] += y;
}

void Boid::clearBuffer() {
    numNeighbors = 0;
    targetPosBuffer[0] = 0;
    targetPosBuffer[1] = 0;
}

void Boid::steerTo(float tx, float ty) {
    if (tx == pos[0] && ty == pos[1])
        return;

    float toAngle = atan2(pos[1] - ty, tx - pos[0]); //true destination angle
    float moveAngle = 0; //what we'll move to in one tick (towards toAngle)

    if (toAngle < 0)
        toAngle += 2*PI;

    if (toAngle > theta)
        if (toAngle - theta <= PI)
            moveAngle = theta + TURN_INCREMENT;
        else
            moveAngle = theta - TURN_INCREMENT;
    else if (theta - toAngle <= PI)
        moveAngle = theta - TURN_INCREMENT;
    else
        moveAngle = theta + TURN_INCREMENT;

    vel[0] = cos(moveAngle);
    vel[1] = -sin(moveAngle);
}
