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
        boids[k].targetPosBuffer[0] = 0; //Clear previous target position
        boids[k].targetPosBuffer[1] = 0;
        boids[k].numNeighbors = 0;
    }

    //Cohesion
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

    for (int k = 0; k < num; k++){
        if (boids[k].numNeighbors > 0){
            boids[k].targetPos[0] = W_COHESION * boids[k].targetPosBuffer[0]/boids[k].numNeighbors;
            boids[k].targetPos[1] = W_COHESION * boids[k].targetPosBuffer[1]/boids[k].numNeighbors;
        } else {
            boids[k].targetPos[0] = boids[k].pos[0];
            boids[k].targetPos[1] = boids[k].pos[1];
        }
    }

    //Adhesion

    //Alignment

    for (int k = 0; k < num; k++)
        boids[k].update();

}



void Flock::draw() {
    for (int k = 0; k < num; k++)
        boids[k].draw();
}
