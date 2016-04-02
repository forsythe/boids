#include <vector>
#include <math.h>
#include <cstdlib>
#include <iostream>

#include "Flock.h"
#include "defs.h"
#include "Boid.h"

using namespace std;

Flock::Flock(int num_rhs) {
    num = num_rhs;
    for (int k = 0; k < num; k++)
        boids.push_back(Boid());
}

float getDist(Boid a, Boid b) {
    return sqrt((b.pos[0]-a.pos[0])*(b.pos[0]-a.pos[0])+(b.pos[1]-a.pos[1])*(b.pos[1]-a.pos[1]));
}

void Flock::update() {

    for (int k = 0; k < num; k++) {
        boids[k].clearBuffer();
    }

    /**********************Cohesion**********************/
    for (int k = 0; k < num; k++) {
        for (int j = k + 1; j < num; j++) {
            if (getDist(boids[k], boids[j]) < BOID_RADIUS) {
                boids[k].numNeighbors++;
                boids[j].numNeighbors++;
                boids[k].addToTargetPosBuffer(boids[j].pos[0], boids[j].pos[1]);
                boids[j].addToTargetPosBuffer(boids[k].pos[0], boids[k].pos[1]);
            }
        }
    }

    for (int k = 0; k < num; k++) {
        if (boids[k].numNeighbors > 0) {
            boids[k].cohesionTargetPos[0] = boids[k].targetPosBuffer[0]/boids[k].numNeighbors;
            boids[k].cohesionTargetPos[1] = boids[k].targetPosBuffer[1]/boids[k].numNeighbors;
        } else {
            boids[k].cohesionTargetPos[0] = boids[k].pos[0];
            boids[k].cohesionTargetPos[1] = boids[k].pos[1];
        }
    }

    /**********************Separation**********************/
    for (int k = 0; k < num; k++) {
        boids[k].clearBuffer();
    }

    for (int k = 0; k < num; k++) {
        for (int j = k + 1; j < num; j++) {
            if (getDist(boids[k], boids[j]) < SEPARATION_BOID_RADIUS) {
                boids[k].numNeighbors++;
                boids[j].numNeighbors++;
                boids[k].addToTargetPosBuffer(boids[j].pos[0], boids[j].pos[1]);
                boids[j].addToTargetPosBuffer(boids[k].pos[0], boids[k].pos[1]);
            }
        }
    }

    for (int k = 0; k < num; k++) {
        if (boids[k].numNeighbors > 0) {
            if (boids[k].targetPosBuffer[0]/boids[k].numNeighbors != boids[k].pos[0]) { //prevent divide by 0
                boids[k].separationTargetPos[0] = boids[k].pos[0] -
                                                  1000/(boids[k].targetPosBuffer[0]/boids[k].numNeighbors - boids[k].pos[0]);
            }
            if (boids[k].targetPosBuffer[1]/boids[k].numNeighbors != boids[k].pos[1]) { //prevent divide by 0
                boids[k].separationTargetPos[1] = boids[k].pos[1] -
                                                  1000/(boids[k].targetPosBuffer[1]/boids[k].numNeighbors - boids[k].pos[1]);
            }
        } else {
            boids[k].separationTargetPos[0] = boids[k].pos[0];
            boids[k].separationTargetPos[1] = boids[k].pos[1];
        }
    }
    /**********************Alignment**********************/
    for (int k = 0; k < num; k++) {
        boids[k].clearBuffer();
        boids[k].sumNeighborTheta = 0;
    }

     for (int k = 0; k < num; k++) {
        for (int j = k + 1; j < num; j++) {
            if (getDist(boids[k], boids[j]) < BOID_RADIUS) {
                boids[k].numNeighbors++;
                boids[j].numNeighbors++;
                boids[k].sumNeighborTheta += boids[j].theta;
                boids[j].sumNeighborTheta += boids[k].theta;
            }
        }
    }

    for (int k = 0; k < num; k++) {
        if (boids[k].numNeighbors > 0) {
            boids[k].alignmentTargetPos[0] = boids[k].pos[0] + cos(boids[k].sumNeighborTheta/boids[k].numNeighbors);
            boids[k].alignmentTargetPos[1] = boids[k].pos[1] - sin(boids[k].sumNeighborTheta/boids[k].numNeighbors);
        } else {
            boids[k].alignmentTargetPos[0] = boids[k].pos[0];
            boids[k].alignmentTargetPos[1] = boids[k].pos[1];
        }
    }




    //end
    for (int k = 0; k < num; k++)
        boids[k].update();

}



void Flock::draw() {
    for (int k = 0; k < num; k++)
        boids[k].draw();
}
