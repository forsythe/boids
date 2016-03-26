#include <vector>
#include <cmath>

#include "Flock.h"
#include "defs.h"
#include "Boid.h"

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
        boids[k].targetPos[0] = 0; //Clear previous target position
        boids[k].targetPos[1] = 0;
    }

    //Cohesion

    for (int k = 0; k < num; k++) {
        int perceivedCenter[2] = {0, 0};
        int numNeighbors = 0;

        for (int j = 0; j < num; j++) {
            if (j == k) continue;

            if (getDist(boids[k], boids[j]) < BOID_RADIUS) {
                numNeighbors++;
                perceivedCenter[0] += boids[j].pos[0];
                perceivedCenter[1] += boids[j].pos[1];
            }
            if (numNeighbors > 0) {
                boids[k].targetPos[0] += W_COHESION * perceivedCenter[0] / numNeighbors;
                boids[k].targetPos[1] += W_COHESION * perceivedCenter[1] / numNeighbors;
            }
        }
    }

    for (int k = 0; k < num; k++) {
        boids[k].update();
    }
}



void Flock::draw() {
    for (int k = 0; k < num; k++)
        boids[k].draw();
}
